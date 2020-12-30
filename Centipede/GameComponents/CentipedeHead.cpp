// Centipede Head

#include "CentipedeHead.h"
#include "Settings.h"
#include "Grid.h"
#include "MushroomField.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "CentipedeBodyFactory.h"
#include "ScoreManager.h"
#include "ExplosionFactory.h"
#include "CentipedeManager.h"

CentipedeHead::CentipedeHead()
	:pMField(0), pCurrentState(0), Pos(sf::Vector2f(0.0f, 0.0f)), col(0), row(0), index(0), pNext(0), pPrev(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2, 45.0f, 0, 7, true, true);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(Settings::CELL_SIZE / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	bitmap = &ResourceManager::GetTextureBitmap("CentipedeHead");
	SetCollider(MainSprite, *bitmap);

	SetDrawOrder(1001);
}

void CentipedeHead::Initialize(sf::Vector2f v, MushroomField* mf, int bodyCnt, CentipedeHeadFactory::Direction dir, CmdScore* death)
{
	pDeath = death;
	pMField = mf;
	pNext = 0;
	Pos = v;
	col = Grid::pixelstoGrid(Pos.x);
	row = Grid::pixelstoGrid(Pos.y);
	index = 0;
	MainSprite.setPosition(Pos);
	RegisterCollision<CentipedeHead>(*this);

	if (dir == CentipedeHeadFactory::Direction::RIGHT) 
	{
		pCurrentState = &MoveFSM::StateTurnDownAndLeft;
		MainSprite.setRotation(180.0f);
	}
	else
	{
		pCurrentState = &MoveFSM::StateTurnDownAndRight;
		MainSprite.setRotation(0.0f);
	}

	CreateBody(bodyCnt);
	CentipedeManager::IncreaseHeadCount();
	CentipedeManager::AddCentipede(this);
}

void CentipedeHead::Initialize(sf::Vector2f pos, MushroomField* mf, Centipede* next, const MoveState* state, int index, float rotation, CmdScore* death)
{
	pDeath = death;
	this->Pos = pos;
	pMField = mf;
	pPrev = 0;
	pNext = next;
	if (next)
		next->setPrev(this);

	if (state == &MoveFSM::StatePoisonedTurnDownAndLeft)
		pCurrentState = &MoveFSM::StateTurnDownAndLeft;
	else if (state == &MoveFSM::StatePoisonedTurnDownAndRight)
		pCurrentState = &MoveFSM::StatePoisonedTurnDownAndRight;
	else
		pCurrentState = state;

	this->index = index;

	MainSprite.setPosition(Pos);
	MainSprite.setRotation(rotation);

	CentipedeManager::IncreaseHeadCount();
	CentipedeManager::AddCentipede(this);
	RegisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Kill()
{
	Centipede* next = pNext;
	Centipede* tmp;
	while (next != 0)
	{
		tmp = next->getNext();
		next->setNext(0);
		next->setPrev(0);
		next->MarkForDestroy();
		next = tmp;
	}
	this->MarkForDestroy();
}

void CentipedeHead::StopMovement()
{
	Centipede* tmp = this;
	while (tmp != 0)
	{
		tmp->setMoveState(&MoveFSM::StateNoMovement);
		tmp = tmp->getNext();
	}
}

void CentipedeHead::CreateBody(int bodyCnt)
{
	if (bodyCnt == 0)
		return;
	
	Centipede* pCurr = this;
	for(int i = 0; i < bodyCnt; i++)
	{
		CentipedeBodyFactory::CreateCentipedeBody(Pos, pMField, pCurr);
		pCurr = pCurr->getNext();
		pCurr->setRotation(MainSprite.getRotation());
	}
}

void CentipedeHead::setNext(Centipede* next)
{
	pNext = next;
}

void CentipedeHead::setPrev(Centipede* prev)
{
	pPrev = prev;
}

Centipede* CentipedeHead::getNext()
{
	return pNext;
}

Centipede* CentipedeHead::getPrev()
{
	return pPrev;
}

int CentipedeHead::getCol()
{
	return col;
}

int CentipedeHead::getRow()
{
	return row;
}

MushroomField* CentipedeHead::getField()
{
	return pMField;
}

float CentipedeHead::getRotation()
{
	return MainSprite.getRotation();
}

int CentipedeHead::getIndex()
{
	return index;
}

void CentipedeHead::setMoveState(const MoveState* state)
{
	pCurrentState = state;
}

const MoveState* CentipedeHead::getMoveState()
{
	return pCurrentState;
}

void CentipedeHead::Update()
{
	MainSprite.Update();

	if (index > static_cast<int>(pCurrentState->GetMoveOffsets().size()) - 1)
	{
		col = Grid::pixelstoGrid(Pos.x);
		row = Grid::pixelstoGrid(Pos.y);

		pCurrentState = pCurrentState->GetNextState(this);
		index = 0;
	}

	Pos.x += pCurrentState->GetMoveOffsets()[index].x;
	Pos.y += pCurrentState->GetMoveOffsets()[index].y;
	MainSprite.setRotation(MainSprite.getRotation() + pCurrentState->GetMoveOffsets()[index].z);
	index++;
	MainSprite.setPosition(Pos);
}

void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeHead::Destroy()
{
	DeregisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Collision(Blaster* b)
{
	ExplosionFactory::CreateExplosion(Pos);
}

void CentipedeHead::Collision(Bullet* b)
{
	ExplosionFactory::CreateExplosion(Pos);
	/* --- Forces the mushroom to spawn in the next cell --- */
	for (int i = index; i < static_cast<int>(pCurrentState->GetMoveOffsets().size()); i++)
	{
		Pos.x += pCurrentState->GetMoveOffsets()[index].x;
		Pos.y += pCurrentState->GetMoveOffsets()[index].y;
	}

	pMField->PlaceMushroom(Grid::pixelstoGrid(Pos.x), Grid::pixelstoGrid(Pos.y));
	Split();
	pNext = 0;
	pPrev = 0;

	ScoreManager::SendScoreCmd(pDeath);
	CentipedeManager::ReduceHeadCount();
	CentipedeManager::RemoveCentipede(this);
	MarkForDestroy();
}

void CentipedeHead::Split()
{
	Centipede* pSegment = pNext;

	// If there's another segment, convert it to a head segment
	if (pSegment)
	{
		CentipedeHeadFactory::ConvertCentipedeBody
		(pSegment->getPos(), pMField, pSegment->getNext(), pSegment->getMoveState(), pSegment->getIndex(), pSegment->getRotation());
		pSegment->setNext(0);
		pSegment->setPrev(0);
		pSegment->MarkForDestroy();
	}

}
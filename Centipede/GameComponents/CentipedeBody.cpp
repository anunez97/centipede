// Centipede Body

#include "CentipedeBody.h"
#include "Grid.h"
#include "Settings.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "CentipedeHeadFactory.h"
#include "MushroomField.h"
#include "ScoreManager.h"
#include "ExplosionFactory.h"

CentipedeBody::CentipedeBody()
	:pMField(0), pCurrentState(0), Pos(sf::Vector2f(0.0f, 0.0f)), col(0), row(0), index(0), pPrev(0), pNext(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeBody"), 8, 2, 45.0f, 0, 7, true, true);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(Settings::CELL_SIZE / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	bitmap = &ResourceManager::GetTextureBitmap("CentipedeBody");
	SetCollider(MainSprite, *bitmap);

	SetDrawOrder(999);
}

CentipedeBody::~CentipedeBody()
{

}

void CentipedeBody::setNext(Centipede* next)
{
	pNext = next;
}

void CentipedeBody::setPrev(Centipede* prev)
{
	pPrev = prev;
}

Centipede* CentipedeBody::getNext()
{
	return pNext;
}

Centipede* CentipedeBody::getPrev()
{
	return pPrev;
}

sf::Vector2f CentipedeBody::getPos()
{
	return Pos;
}

float CentipedeBody::getRotation()
{
	return MainSprite.getRotation();
}

void CentipedeBody::Initialize(sf::Vector2f v, MushroomField* mf, Centipede* prev, CmdScore* death)
{
	pDeath = death;
	pPrev = prev;
	pNext = 0;
	prev->setNext(this);
	pMField = mf;
	pCurrentState = &MoveFSM::StateNoMovement;
	index = 0;
	Pos = v;
	col = Grid::pixelstoGrid(v.x);
	row = Grid::pixelstoGrid(v.y);

	MainSprite.setPosition(Pos);
	RegisterCollision<CentipedeBody>(*this);
	
}

void CentipedeBody::Split()
{
	Centipede* pSegment = pNext;
	
	// Avoids bug where the body and the previous segment are both hit in the same frame
	if(pPrev)
		pPrev->setNext(0);

	// If not last segment
	if (pSegment != 0)
	{
		CentipedeHeadFactory::ConvertCentipedeBody
		(pSegment->getPos(), pMField, pSegment->getNext(), pSegment->getMoveState(), pSegment->getIndex(), pSegment->getRotation());
		pSegment->setPrev(0);
		pSegment->setNext(0);
		pSegment->MarkForDestroy();
	}
}

void CentipedeBody::setMoveState(const MoveState* state)
{
	if (pNext)
	{
		pNext->setMoveState(pCurrentState);
	}

	pCurrentState = state;
	index = 0;
}

const MoveState* CentipedeBody::getMoveState()
{
	return pCurrentState;
}

void CentipedeBody::setRotation(float degree)
{
	MainSprite.setRotation(degree);
}

int CentipedeBody::getRow()
{
	return row;
}

int CentipedeBody::getCol()
{
	return col;
}

MushroomField* CentipedeBody::getField()
{
	return pMField;
}

int CentipedeBody::getIndex()
{
	return index;
}

void CentipedeBody::Update()
{
	MainSprite.Update();

	if (index > static_cast<int>(pCurrentState->GetMoveOffsets().size()) - 1)
	{
		pCurrentState = pNextState;
		index = 0;
	}

	if(pPrev)
		pNextState = pPrev->getMoveState();

	Pos.x += pCurrentState->GetMoveOffsets()[index].x;
	Pos.y += pCurrentState->GetMoveOffsets()[index].y;
	MainSprite.setRotation(MainSprite.getRotation() + pCurrentState->GetMoveOffsets()[index].z);
	

	MainSprite.setPosition(Pos);
	index++;
}

void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeBody::Destroy()
{
	DeregisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::Collision(Blaster* b)
{
	ExplosionFactory::CreateExplosion(Pos);
	Split();
	pNext = 0;
	pPrev = 0;
	MarkForDestroy();
}

void CentipedeBody::Collision(Bullet* b)
{
	ExplosionFactory::CreateExplosion(Pos);

	// Force mushroom to spawn in next cell
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

	MarkForDestroy();
}
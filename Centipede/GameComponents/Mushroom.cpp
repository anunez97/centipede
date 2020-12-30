// Mushroom

#include "Mushroom.h"
#include "MushroomField.h"
#include "Settings.h"
#include "Grid.h"
#include "ScoreManager.h"

Mushroom::Mushroom()
	:mfield(0), row(0), col(0), maxHealth(4), health(0), mState(MushroomState::NORMAL), bitmap(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0f, 0, 7, false, false);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(Settings::CELL_SIZE / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	SetDrawOrder(10);

	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(MainSprite, *bitmap);
}

void Mushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Collision(Bullet* other)
{
	health--;

	/* --- Update Mushroom Sprite --- */
	if (health <= 0) {
		if (mState == NORMAL)
			ScoreManager::SendScoreCmd(pNormalMushroomDeath);
		else
			ScoreManager::SendScoreCmd(pPoisonMushroomDeath);

		mfield->mushroomDestroyed(this);
		MarkForDestroy();
	}
	else MainSprite.NextFrame();
}

void Mushroom::Poisoned()
{
	if (mState != POISON)
	{
		MainSprite.SetFrame(MainSprite.GetFrame() + health);
		mState = POISON;
		mfield->GetGrid()->UpdateCellState(col, row, Grid::CellState::POISON);
	}
}

void Mushroom::Collision(Spider* other)
{
	mfield->mushroomDestroyed(this);
	MarkForDestroy();
}

sf::Vector2f Mushroom::getPos()
{
	return Pos;
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);
}

int Mushroom::getRow()
{
	return row;
}

int Mushroom::getCol()
{
	return col;
}

int Mushroom::getHealth()
{
	return health;
}

void Mushroom::SetVars(sf::Vector2f pos, int col, int row, MushroomField* mf, CmdScore* normal, CmdScore* poison)
{
	Pos = pos;
	this->col = col;
	this->row = row;
	mfield = mf;
	pNormalMushroomDeath = normal;
	pPoisonMushroomDeath = poison;
}

int Mushroom::Regen()
{
	if (health != maxHealth || mState == MushroomState::POISON)
	{
		health = maxHealth;
		mState = MushroomState::NORMAL;
		MainSprite.SetFrame(0);
		return 1;
	}
	else
		return 0;
}

void Mushroom::Initialize()
{
	mState = MushroomState::NORMAL;
	health = maxHealth;
	MainSprite.SetFrame(0);

	MainSprite.setPosition(Pos);
	RegisterCollision<Mushroom>(*this);
}

Mushroom::MushroomState Mushroom::getState()
{
	return this->mState;
}

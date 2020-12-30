// Flea

#include "Flea.h"
#include "Grid.h"
#include "ScoreManager.h"
#include "CritterManager.h"
#include "WaveManager.h"
#include "SoundManager.h"
#include "ExplosionFactory.h"
#include "FleaManager.h"

Flea::Flea()
	:Pos(sf::Vector2f(0.0f, 0.0f)), SPEED(200.0f), currRow(0), col(0), nextRow(0), mfield(0), maxHealth(2), health(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2, 15.0f, 0, 3, true, true);

	//7.0f is the offset of the flea sprite
	MainSprite.setOrigin(sf::Vector2f((MainSprite.getTextureRect().width / 2.0f) - 7.0f, MainSprite.getTextureRect().height / 2.0f));
	// The Flea sprite is 9 pixels wide
	MainSprite.setScale(Settings::CELL_SIZE / 2.0f / 9.0f, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	bitmap = &ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, *bitmap);

	SetDrawOrder(1000);
}

void Flea::Update()
{
	MainSprite.Update();
	offset = SPEED * Game::FrameTime();

	move();

	/* --- When Flea goes offscreen, it dies --- */
	if (Pos.y > WindowManager::Window().getDefaultView().getSize().y + (static_cast<float>(MainSprite.getTextureRect().height / 2.0f)))
	{
		// If there isnt enough mushrooms in the player area, another flea spawns
		MarkForDestroy();
		FleaManager::ReduceFleaCount();
		FleaManager::SpawnFlea(mfield->GetMushroomCount(), mfield);
	}
}

void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::Destroy()
{
	DeregisterCollision<Flea>(*this);
}

void Flea::Collision(Blaster* b)
{
	ExplosionFactory::CreateExplosion(Pos);
	MarkForDestroy();
}

void Flea::Collision(Bullet* b)
{
	if (--health == 0)
	{
		// If there isnt enough mushrooms in the player area, another flea spawns
		FleaManager::ReduceFleaCount();
		FleaManager::SpawnFlea(mfield->GetMushroomCount(), mfield);

		ScoreManager::SendScoreCmd(pDeath);

		ExplosionFactory::CreateExplosion(Pos);
		MarkForDestroy();
	}
	else SPEED = 400.0f;
}

void Flea::Initialize(sf::Vector2f v, MushroomField *mf, CmdScore* death)
{
	pDeath = death;
	mfield = mf; // Access to mushroom field to spawn mushrooms
	col = Grid::pixelstoGrid(v.x);
	currRow = Grid::pixelstoGrid(v.y);
	nextRow = currRow + 1;
	Pos = v;

	SPEED = 200.f;

	health = maxHealth;

	MainSprite.setPosition(Pos);

	RegisterCollision<Flea>(*this);
}

void Flea::move()
{
	Pos.y += offset;
	MainSprite.setPosition(Pos);

	currRow = Grid::pixelstoGrid(Pos.y);

	if (currRow == nextRow)
	{
		spawnMushroom();
		nextRow++;
	}

}

void Flea::spawnMushroom()
{
	if (health == maxHealth)
	{
		if (currRow < Settings::MUSHROOM_BROW && currRow >= Settings::MUSHROOM_TROW && !mfield->hasMushroom(currRow, col))
		{
			if (rand() % 100 + 1 > 80) // % chance of a mushroom spawning
			{
				mfield->PlaceMushroom(col, currRow);
			}
		}
	}
}
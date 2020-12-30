// Scorpion

#include "Scorpion.h"
#include "Settings.h"
#include "ScoreManager.h"
#include "ScorpionManager.h"
#include "WaveManager.h"
#include "ExplosionFactory.h"
#include "Grid.h"

Scorpion::Scorpion()
	:Pos(sf::Vector2f(0.0f, 0.0f)), SPEED(100.0f), dir(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1, 15.0f, 0, 3, true, true);
	MainSprite.setOrigin(sf::Vector2f(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f));
	MainSprite.setScale(Settings::CELL_SIZE * 2.0f / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	bitmap = &ResourceManager::GetTextureBitmap("Scorpion");

	SetCollider(MainSprite, *bitmap);

	SetDrawOrder(1000);
}

void Scorpion::Update()
{
	MainSprite.Update();
	offset = SPEED * Game::FrameTime();

	move();

	// Goes off screen
	if (Pos.x <= -MainSprite.getTextureRect().width)
	{
		//ConsoleMsg::WriteLine("Scorpion offscreen");
		ScorpionManager::ReduceScorpionCount();
		MarkForDestroy();
	}
	else if (Pos.x >= WindowManager::Window().getDefaultView().getSize().x + MainSprite.getTextureRect().width)
	{
		//ConsoleMsg::WriteLine("Scorpion offscreen");
		ScorpionManager::ReduceScorpionCount();
		MarkForDestroy();
	}
}

void Scorpion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Scorpion::Destroy()
{
	DeregisterCollision<Scorpion>(*this);
}

void Scorpion::Collision(Bullet* b)
{
	ScoreManager::SendScoreCmd(pDeath);
	ScorpionManager::ReduceScorpionCount();
	ExplosionFactory::CreateExplosion(Pos);
	MarkForDestroy();
}

void Scorpion::Initialize(sf::Vector2f v, CmdScore* death)
{
	if (v.x > Settings::CELL_SIZE / 2.0f)
	{
		dir = -1.0f;
		nextCol = Settings::NUM_COLS - 1;
	}
	else
	{
		dir = 1.0f;
		nextCol = 0;
	}

	pDeath = death;

	Pos = v;
	Pos.x += -dir * MainSprite.getTextureRect().width;

	row = Grid::pixelstoGrid(v.y);

	/* --- Resets the scale after recycling --- */
	MainSprite.setScale(Settings::CELL_SIZE * 2.0f / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);
	MainSprite.setScale(MainSprite.getScale().x * -dir, MainSprite.getScale().y);
	MainSprite.setPosition(Pos);

	RegisterCollision<Scorpion>(*this);
}

void Scorpion::move()
{
	Pos += sf::Vector2f(dir * offset, 0);

	currCol = Grid::pixelstoGrid(Pos.x);

	if (currCol == nextCol)
	{
		ScorpionManager::PoisonMushroom(currCol, row);
		nextCol = nextCol + (int)dir;
	}

	MainSprite.setPosition(Pos);
}
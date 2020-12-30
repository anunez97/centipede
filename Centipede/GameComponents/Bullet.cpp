// Bullet

#include "Bullet.h"
#include "Settings.h"
#include "Grid.h"

Bullet::Bullet()
	:SPEED(900.0f), rowLimit(0), bptr(0), Pos(sf::Vector2f(0.0f, 0.0f)), origPos(sf::Vector2f(0.0f, 0.0f))
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Bullet"), 1, 1);
	MainSprite.setOrigin((float)MainSprite.getTextureRect().width / 2.0f, (float)MainSprite.getTextureRect().height / 2.0f);

	MainSprite.setScale(Settings::CELL_SIZE / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	bitmap = ResourceManager::GetTextureBitmap("Bullet");
	SetCollider(MainSprite, bitmap);
}

void Bullet::Initialize(sf::Vector2f p, Blaster* b)
{
	origPos = p;
	Pos = p;
	bptr = b;
	currRow = Grid::pixelstoGrid(Pos.y);

	RegisterCollision<Bullet>(*this);
}

void Bullet::move()
{
	Pos.y -= Game::FrameTime() * SPEED;
	MainSprite.setPosition(Pos);
	currRow = Grid::pixelstoGrid(Pos.y);
}

void Bullet::Update()
{
	move();

	// Check if it goes offscreen
	if (currRow <= rowLimit) 
	{
		MarkForDestroy();
		bptr->reload();
	}
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Bullet::Destroy()
{
	DeregisterCollision<Bullet>(*this);
}

sf::Vector2f Bullet::GetOrigPos()
{
	return origPos;
}

void Bullet::Collision(Mushroom* other)
{
	bptr->reload();
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	bptr->reload();
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	bptr->reload();
	MarkForDestroy();
}

void Bullet::Collision(Flea* other)
{
	bptr->reload();
	MarkForDestroy();
}

void Bullet::Collision(Glyph* other)
{
	bptr->reload();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeHead* other)
{
	bptr->reload();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeBody* other)
{
	bptr->reload();
	MarkForDestroy();
}
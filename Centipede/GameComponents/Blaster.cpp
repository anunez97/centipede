// Blaster

#include "Blaster.h"
#include "Bullet.h"
#include "Settings.h"
#include "BulletFactory.h"
#include "Grid.h"
#include "Player.h"
#include "ExplosionFactory.h"

Blaster::Blaster()
	:bulletCnt(1), pPlayer(0), pBullet(0), currPos(sf::Vector2f(0.0f, 0.0f))
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(Settings::CELL_SIZE / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	SetDrawOrder(1000);

	bitmap = &ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(MainSprite, *bitmap);
}

void Blaster::Initialize(sf::Vector2f v, Player* p)
{
	currPos = v;
	pPlayer = p;
	MainSprite.setPosition(currPos);
	RegisterCollision<Blaster>(*this);
}

void Blaster::Update()
{
	MainSprite.setPosition(currPos);

	Tools::Clamp<float>(currPos.x, Grid::gridtoPixels(Settings::LCOLBORDER), Grid::gridtoPixels(Settings::RCOLBORDER));
	Tools::Clamp<float>(currPos.y, Grid::gridtoPixels(Settings::TROWBORDER), Grid::gridtoPixels(Settings::BROWBORDER));

}

void Blaster::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Blaster::Destroy()
{
	if (pBullet)
	{
		pBullet->MarkForDestroy();
		bulletCnt++;
	}

	DeregisterCollision<Blaster>(*this);
}

void Blaster::Collision(Mushroom* other) 
{
	currPos = prevPos;
	MainSprite.setPosition(currPos);
}

void Blaster::Collision(Spider* other)
{
	pPlayer->PlayerDeath();
	ExplosionFactory::CreateExplosion(currPos);
	
	MarkForDestroy();
}

void Blaster::Collision(Flea* other)
{
	pPlayer->PlayerDeath();
	ExplosionFactory::CreateExplosion(currPos);
	MarkForDestroy();
}

void Blaster::Collision(CentipedeHead* other)
{
	pPlayer->PlayerDeath();
	ExplosionFactory::CreateExplosion(currPos);
	MarkForDestroy();
}

void Blaster::Collision(CentipedeBody* other)
{
	pPlayer->PlayerDeath();
	ExplosionFactory::CreateExplosion(currPos);
	MarkForDestroy();
}

void Blaster::fire() {
	if (bulletCnt > 0)
	{
		pBullet = BulletFactory::CreateBullet(currPos, this);
		bulletCnt--;
	}
}

void Blaster::reload() 
{
	pBullet = 0;
	bulletCnt++;
}

void Blaster::move(sf::Vector2f v)
{
	prevPos = currPos;
	currPos.x += v.x;
	currPos.y += v.y;
}

sf::Vector2f Blaster::GetPos()
{
	return currPos;
}
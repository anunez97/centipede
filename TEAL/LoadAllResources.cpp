// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../SPLevel.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene(new SPLevel());

	AddTexture("Blaster", "/../../../../../reference/Asset/Sprites/blaster.png");
	AddTexture("Mushroom", "/../../../../../reference/Asset/Sprites/mushroom.png");
	AddTexture("Bullet", "/../../../../../reference/Asset/Sprites/bullet.png");
	AddTexture("Spider", "/../../../../../reference/Asset/Sprites/spider.png");
	AddTexture("Scorpion", "/../../../../../reference/Asset/Sprites/scorpion.png");
	AddTexture("Flea", "/../../../../../reference/Asset/Sprites/flea.png");
	AddTexture("CentipedeHead", "/../../../../../reference/Asset/Sprites/centipede_head.png");
	AddTexture("CentipedeBody", "/../../../../../reference/Asset/Sprites/centipede_segment.png");
	AddTexture("Font", "/../../../../../reference/Asset/Sprites/FONTwPLAYER.bmp");
	AddTexture("Explosion", "/../../../../../reference/Asset/Sprites/death.png");

	AddSound("CentiBeat", "/../../../../../reference/Asset/Sounds/beat.wav");
	AddSound("ScorpionSound", "/../../../../../reference/Asset/Sounds/scorpion_new.wav");
	AddSound("SpiderSound", "/../../../../../reference/Asset/Sounds/spider_new.wav");
	AddSound("FleaSound", "/../../../../../reference/Asset/Sounds/flea_new.wav");
	AddSound("BulletSound", "/../../../../../reference/Asset/Sounds/fire1.wav");
	AddSound("PlayerDeath", "/../../../../../reference/Asset/Sounds/death.wav");
}


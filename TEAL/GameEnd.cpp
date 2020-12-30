// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"
#include "..//CentipedeManager.h"
#include "..//FleaManager.h"
#include "..//WaveManager.h"
#include "..//PlayerManager.h"
#include "..//ScoreManager.h"
#include "..//SoundManager.h"

#include "..//BlasterFactory.h"
#include "..//BulletFactory.h"
#include "..//CentipedeBodyFactory.h"
#include "..//CentipedeHeadFactory.h"
#include "..//FleaFactory.h"
#include "..//ScorpionFactory.h"
#include "..//SpiderFactory.h"
#include "..//MushroomFactory.h"
#include "..//GlyphFactory.h"
#include "..//ExplosionFactory.h"
#include "..//MushroomRegen.h"

#include "..//HUD.h"


void Game::GameEnd()
{
	// Empty for now
	CentipedeManager::Terminate();
	FleaManager::Terminate();
	WaveManager::Terminate();
	PlayerManager::Terminate();
	ScoreManager::Terminate();

	BlasterFactory::Terminate();
	BulletFactory::Terminate();
	CentipedeBodyFactory::Terminate();
	CentipedeHeadFactory::Terminate();
	FleaFactory::Terminate();
	ScorpionFactory::Terminate();
	SpiderFactory::Terminate();
	MushroomFactory::Terminate();
	GlyphFactory::Terminate();
	ExplosionFactory::Terminate();
	MushroomRegen::Terminate();

	SoundManager::Terminate();
	HUD::Terminate();
}
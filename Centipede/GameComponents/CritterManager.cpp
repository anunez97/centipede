// Critter Manager

#include "CritterManager.h"
#include "Settings.h"
#include "Grid.h"
#include "Scorpion.h"
#include "Spider.h"
#include "Flea.h"
#include "CentipedeHead.h"
#include "FleaFactory.h"
#include "ScorpionFactory.h"
#include "SpiderFactory.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBody.h"

CritterManager* CritterManager::ptrInstance = nullptr;

CritterManager::CritterManager()
	:FleaSpawn(true), SpiderSpawn(true), ScorpionSpawn(true), FleaMushroomCnt(0), 
	FleaCount(0), ScorpionCount(0), SpiderCount(0), SpiderSpeed(0)
{
}

void CritterManager::privSpawnSpider()
{
	if (SpiderSpawn && SpiderCount == 0)
	{
		Pos = sf::Vector2f(WindowManager::Window().getView().getSize().x * static_cast<float>(rand() % 2), Grid::gridtoPixels(Settings::SPIDER_TBORDER));
		//SpiderFactory::CreateSpider(Pos);
		SpiderCount++;
	}
}

void CritterManager::privSpawnScorpion()
{
	if (ScorpionSpawn && ScorpionCount == 0)
	{
		Pos = sf::Vector2f(WindowManager::Window().getView().getSize().x * static_cast<float>(rand() % 2), 
			Grid::gridtoPixels(rand() % Settings::SCORPION_ROW_LIMIT + 1));
		ScorpionFactory::CreateScorpion(Pos);
		ScorpionCount++;
	}
}

void CritterManager::privSpawnFlea(int currCount, MushroomField* mf)
{
	// Check if fleas can spawn, if theres too few mushrooms in the player area, and if theres already a flea on screen
	if (FleaSpawn && FleaMushroomCnt >= currCount && FleaCount == 0)
	{
		int col = rand() % Settings::NUM_COLS;
		Pos = sf::Vector2f(Grid::gridtoPixels(col), Settings::FLEA_SPAWN);
		FleaFactory::CreateFlea(Pos, mf);
		FleaCount++;
	}
}

void CritterManager::privSpawnCentipedeHead(sf::Vector2f pos, int bodyCnt, MushroomField* mfield)
{
	//sf::Vector2f pos = sf::Vector2f(Grid::gridtoPixels(15), Grid::gridtoPixels(0));
	CentipedeHeadFactory::CreateCentipedeHead(pos, bodyCnt, mfield);
}

void CritterManager::privSetFleaSpawn(bool b)
{
	FleaSpawn = b;
}

void CritterManager::privSetMushroomCnt(int count)
{
	FleaMushroomCnt = count;
}

void CritterManager::privReduceFleaCount()
{
	FleaCount--;
}

void CritterManager::privReduceScorpionCount()
{
	ScorpionCount--;
}

void CritterManager::privReduceSpiderCount()
{
	SpiderCount--;
}

void CritterManager::privSetScorpionSpawn(bool b)
{
	ScorpionSpawn = b;
}


void CritterManager::privSetSpiderSpawn(bool b)
{
	SpiderSpawn = b;
}

void CritterManager::privSetSpiderSpeed(int val)
{
	SpiderSpeed = val;
}

void CritterManager::Terminate()
{
	delete ptrInstance;

	ptrInstance = nullptr;
}
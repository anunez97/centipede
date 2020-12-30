// Scorpion Manager

#include "ScorpionManager.h"
#include "ScorpionFactory.h"
#include "WaveManager.h"
#include "Scorpion.h"
#include "SoundManager.h"
#include "PlayerManager.h"
#include "MushroomField.h"

#include "Settings.h"
#include "Grid.h"

ScorpionManager* ScorpionManager::ptrInstance = nullptr;

ScorpionManager::ScorpionManager()
	:ScorpionFrequency(0.0f), ScorpionCount(0), ScorpionSpawning(true), pScorpion(0)
{
}

void ScorpionManager::privSpawnScorpion()
{
	if (ScorpionSpawning && ScorpionCount < 1)
	{
		sf::Vector2f pos = sf::Vector2f(WindowManager::Window().getView().getSize().x * static_cast<float>(rand() % 2),
			Grid::gridtoPixels(rand() % Settings::SCORPION_ROW_LIMIT + 1));
		pScorpion = ScorpionFactory::CreateScorpion(pos);
		ScorpionCount++;
	}
}

void ScorpionManager::privSetScorpionSpawn(bool b)
{
	ConsoleMsg::WriteLine("Scorpion Spawning Set");
	ScorpionSpawning = b;
}

void ScorpionManager::privSetScorpionFrequency(float val)
{
	ConsoleMsg::WriteLine("Scorpion Frequency Set");
	ScorpionFrequency = val;
	SetAlarm(0, ScorpionFrequency);
}

void ScorpionManager::privReduceScorpionCount()
{
	ScorpionCount--;
	ScorpionFactory::ScorpionDeath();
	SetAlarm(0, ScorpionFrequency);
}

void ScorpionManager::privReset()
{
	if (pScorpion)
		pScorpion->MarkForDestroy();
	ScorpionFactory::ScorpionDeath();
	ScorpionCount = 0;
}

void ScorpionManager::Alarm0()
{
	privSpawnScorpion();
}

void ScorpionManager::PoisonMushroom(int col, int row)
{
	PlayerManager::GetCurrentField()->PoisonMushroom(col, row);
}

void ScorpionManager::privTerminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
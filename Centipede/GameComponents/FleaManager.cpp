// Flea Manager

#include "FleaManager.h"
#include "FleaFactory.h"
#include "Flea.h"
#include "SoundManager.h"

#include "Settings.h"
#include "Grid.h"

FleaManager* FleaManager::ptrInstance = nullptr;

FleaManager::FleaManager()
	:FleaCount(0), FleaSpawning(true), MushroomCount(0), pFlea(0)
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::FleaSound);
}

void FleaManager::privSpawnFlea(int count, MushroomField* mf)
{
	if (FleaSpawning && FleaCount < 1 && MushroomCount >= count)
	{
		SoundManager::SendPlayCmd(pSound);

		int col = rand() % Settings::NUM_COLS;
		sf::Vector2f pos = sf::Vector2f(Grid::gridtoPixels(col), 0.0f);
		pFlea = FleaFactory::CreateFlea(pos, mf);
		FleaCount++;
	}
}

void FleaManager::privSetFleaSpawn(bool b)
{
	ConsoleMsg::WriteLine("Flea Spawning Set");
	FleaSpawning = b;
}

void FleaManager::privSetMushroomCountTrigger(int count)
{
	ConsoleMsg::WriteLine("Flea Mushroom Trigger Set");
	MushroomCount = count;
}

void FleaManager::privReduceFleaCount()
{
	SoundManager::SendStopCmd(pSound);
	FleaCount--;
}

void FleaManager::privReset()
{
	SoundManager::SendStopCmd(pSound);
	FleaCount = 0;
	if (pFlea)
		pFlea->MarkForDestroy();
}

void FleaManager::Terminate()
{
	delete Instance().pSound;
	delete ptrInstance;
	ptrInstance = nullptr;
}
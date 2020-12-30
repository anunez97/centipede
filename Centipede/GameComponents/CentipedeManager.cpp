// Centipede Manager

#include "CentipedeManager.h"
#include "CentipedeHeadFactory.h"

#include "WaveManager.h"
#include "PlayerManager.h"
#include "SoundManager.h"

#include "CentipedeHead.h"

#include "Grid.h"
#include "Settings.h"

CentipedeManager* CentipedeManager::ptrInstance = nullptr;

CentipedeManager::CentipedeManager()
	:CentipedeSpeed(0), SoloHeadCount(0), SoloHeadSpeed(0), CentipedeHeadCount(0)
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::CentipedeBeat);
}

void CentipedeManager::privSpawnCentipede(int bodyCount, MushroomField* mf)
{
	if (centiHeads.size() == 0)
		SoundManager::SendPlayCmd(pSound);

	sf::Vector2f pos = sf::Vector2f(Grid::gridtoPixels(Settings::NUM_COLS / 2), Grid::gridtoPixels(0));
	CentipedeHeadFactory::CreateCentipedeHead(pos, bodyCount, mf);
}

void CentipedeManager::privSetCentipedeSpeed(int speed)
{
	CentipedeSpeed = speed;
}

void CentipedeManager::privSpawnSoloHead()
{

}

void CentipedeManager::privSetSoloHeadCount(int count)
{
	SoloHeadCount = count;
}

void CentipedeManager::privSetSoloHeadSpeed(int speed)
{
	SoloHeadSpeed = speed;
}

void CentipedeManager::ReduceHeadCount()
{
	Instance().CentipedeHeadCount--;
	if (Instance().CentipedeHeadCount == 0)
	{
		PlayerManager::IncreaseCurrentWave();
		WaveManager::StartNextWave();
		CentipedeHeadFactory::LevelFinished();
	}
}

void CentipedeManager::privReset()
{
	SoundManager::SendStopCmd(pSound);
	CentipedeHeadCount = 0;
	CentipedeHead* c;
	while (Instance().centiHeads.size() > 0)
	{
		c = Instance().centiHeads.back();
		c->Kill();
		Instance().centiHeads.pop_back();
	}
}

void CentipedeManager::privAddCentipede(CentipedeHead* c)
{
	Instance().centiHeads.push_back(c);
}

void CentipedeManager::privRemoveCentipede(CentipedeHead* c)
{
	Instance().centiHeads.remove(c);
}

void CentipedeManager::privStopMovement()
{
	for (size_t i = 0; i < centiHeads.size(); i++)
	{
		centiHeads.front()->StopMovement();
		centiHeads.push_back(centiHeads.front());
		centiHeads.pop_front();
	}
}

void CentipedeManager::IncreaseHeadCount()
{
	Instance().CentipedeHeadCount++;
}

void CentipedeManager::privTerminate()
{
	delete pSound;
	delete ptrInstance;
	ptrInstance = nullptr;
}
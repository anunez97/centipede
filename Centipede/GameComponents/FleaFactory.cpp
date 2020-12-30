// Flea Factory

#include "FleaFactory.h"
#include "FleaObjectPool.h"
#include "Flea.h"
#include "ScoreManager.h"
#include "CmdScore.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;

FleaFactory::FleaFactory()
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);
}

Flea* FleaFactory::privCreateFlea(sf::Vector2f pos, MushroomField* mf)
{
	Flea* f = FleaPool.getFlea();

	f->SetExternalManagement(RecycleFlea);

	f->Initialize(pos, mf, pDeath);

	return f;
}

void FleaFactory::privRecycleFlea(GameObject *ob)
{
	FleaPool.returnFlea(static_cast<Flea*>(ob));	
}

void FleaFactory::privTerminate()
{
	delete pDeath;
	delete ptrInstance;
	ptrInstance = nullptr;
}
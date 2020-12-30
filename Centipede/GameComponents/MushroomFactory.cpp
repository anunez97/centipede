// Mushroom Factory

#include "MushroomFactory.h"
#include "MushroomObjectPool.h"
#include "Mushroom.h"
#include "MushroomField.h"
#include "ScoreManager.h"
#include "CmdScore.h"

MushroomFactory* MushroomFactory::ptrInstance = nullptr;

MushroomFactory::MushroomFactory()
{
	pNormalMushroomDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
	pPoisonMushroomDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::PoisonMushroomKilled);
}

Mushroom* MushroomFactory::privCreateMushroom(sf::Vector2f pos, int c, int r, MushroomField* mf)
{
	Mushroom* m = MushroomPool.getMushroom();

	m->SetExternalManagement(RecycleMushroom);

	m->SetVars(pos, c, r, mf, pNormalMushroomDeath, pPoisonMushroomDeath);

	return m;
}

void MushroomFactory::privRecycleMushroom(GameObject* ob)
{
	MushroomPool.returnMushroom(static_cast<Mushroom*>(ob));
}

void MushroomFactory::privTerminate()
{
	delete pNormalMushroomDeath;
	delete pPoisonMushroomDeath;

	delete ptrInstance;
	ptrInstance = nullptr;
}
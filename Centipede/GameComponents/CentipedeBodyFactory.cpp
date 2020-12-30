// Centipede Body Factory

#include "CentipedeBodyFactory.h"
#include "CentipedeBodyObjectPool.h"
#include "CentipedeBody.h"
#include "ScoreManager.h"
#include "CmdScore.h"

CentipedeBodyFactory* CentipedeBodyFactory::ptrInstance = nullptr;

CentipedeBodyFactory::CentipedeBodyFactory()
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeBodyKilled);
}

void CentipedeBodyFactory::privCreateCentipedeBody(sf::Vector2f pos, MushroomField* mf, Centipede* prev)
{
	CentipedeBody* c = CentipedeBodyPool.getCentipedeBody();

	c->SetExternalManagement(RecycleCentipedeBody);

	c->Initialize(pos, mf, prev, pDeath);
}

void CentipedeBodyFactory::privRecycleCentipedeBody(GameObject* ob)
{
	CentipedeBodyPool.returnCentipedeBody(static_cast<CentipedeBody*>(ob));
}

void CentipedeBodyFactory::privTerminate()
{
	delete pDeath;

	delete ptrInstance;
	ptrInstance = nullptr;
}
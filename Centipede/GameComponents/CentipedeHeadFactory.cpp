// CentipedeHead Factory

#include "CentipedeHeadFactory.h"
#include "CentipedeHeadObjectPool.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "CentipedeBodyFactory.h"
#include "ScoreManager.h"
#include "CmdScore.h"

CentipedeHeadFactory* CentipedeHeadFactory::ptrInstance = nullptr;

CentipedeHeadFactory::CentipedeHeadFactory()
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeHeadKilled);
	pLvlFinished = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::LevelFinished);
}

void CentipedeHeadFactory::privCreateCentipedeHead(sf::Vector2f pos, int bodyCnt, MushroomField* mf)
{
	CentipedeHead* c = CentipedeHeadPool.getCentipedeHead();

	c->SetExternalManagement(RecycleCentipedeHead);

	if (rand() % 2)
	{
		c->Initialize(pos, mf, bodyCnt, Direction::RIGHT, pDeath);
	}
	else
		c->Initialize(pos, mf, bodyCnt, Direction::LEFT, pDeath);

}

void CentipedeHeadFactory::privRecycleCentipedeHead(GameObject* ob)
{
	CentipedeHeadPool.returnCentipedeHead(static_cast<CentipedeHead*>(ob));
}

void CentipedeHeadFactory::privConvertCentipedeBody(sf::Vector2f pos, MushroomField* mf, Centipede* next, const MoveState* state, int index, float rotation)
{
	CentipedeHead* c = CentipedeHeadPool.getCentipedeHead();

	c->SetExternalManagement(RecycleCentipedeHead);

	c->Initialize(pos, mf, next, state, index, rotation, pDeath);
}

void CentipedeHeadFactory::LevelFinished()
{
	ScoreManager::SendScoreCmd(Instance().pLvlFinished);
}

void CentipedeHeadFactory::Terminate()
{
	delete Instance().pLvlFinished;
	delete Instance().pDeath;
	delete ptrInstance;
	ptrInstance = nullptr;
}
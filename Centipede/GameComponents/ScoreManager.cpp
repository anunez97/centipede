// Score Manager

#include "ScoreManager.h"
#include "CmdScoreValue.h"
#include "CmdScoreByDistance.h"
#include "PlayerManager.h"

ScoreManager* ScoreManager::ptrInstance = nullptr;

ScoreManager::ScoreManager()
{
}

CmdScore* ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	CmdScore* pCmd = nullptr;

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = new CmdScoreValue(FleaDeath);
		break;
	case ScoreEvents::ScorpionKilled:
		pCmd = new CmdScoreValue(ScorpionDeath);
		break;
	case ScoreEvents::CentipedeHeadKilled:
		pCmd = new CmdScoreValue(CentipedeHeadDeath);
		break;
	case ScoreEvents::CentipedeBodyKilled:
		pCmd = new CmdScoreValue(CentipedeBodyDeath);
		break;
	case ScoreEvents::LevelFinished:
		pCmd = new CmdScoreValue(LevelFinished);
		break;
	case ScoreEvents::CloseSpiderKilled:
		pCmd = new CmdScoreByDistance(SpiderDistanceClose, SpiderDeathClose);
		break;
	case ScoreEvents::MediumSpiderKilled:
		pCmd = new CmdScoreByDistance(SpiderDistanceMedium, SpiderDeathMedium);
		break;
	case ScoreEvents::FarSpiderKilled:
		pCmd = new CmdScoreByDistance(SpiderDistanceFar, SpiderDeathFar);
		break;
	case ScoreEvents::MushroomKilled:
		pCmd = new CmdScoreValue(MushroomDeath);
		break;
	case ScoreEvents::PoisonMushroomKilled:
		pCmd = new CmdScoreValue(PoisonMushroomDeath);
		break;
	case ScoreEvents::MushroomRegen:
		pCmd = new CmdScoreValue(MushroomRegen);
		break;
	default:
		ConsoleMsg::WriteLine("Nothing");
	}

	return pCmd;
}

void ScoreManager::AddScore(int val)
{
	PlayerManager::AddScore(val);
}

void ScoreManager::SendScoreCmd(CmdScore* c)
{
	Instance().QueueCmds.push(c);
}

void ScoreManager::privProcessScore()
{
	CmdScore* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}
}

void ScoreManager::Terminate()
{
	delete ptrInstance;

	ptrInstance = nullptr;
}
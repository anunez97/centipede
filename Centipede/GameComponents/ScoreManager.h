// Score Manager

#ifndef _ScoreManager
#define _ScoreManager

#include "TEAL/CommonElements.h"
#include <queue>

class CmdScore;

class ScoreManager
{
private:
	static const int FleaDeath = 200;
	static const int ScorpionDeath = 1000;
	static const int CentipedeHeadDeath = 100;
	static const int CentipedeBodyDeath = 10;
	static const int LevelFinished = 1000;

	static const int SpiderDeathClose = 900;
	static const int SpiderDistanceClose = 100;
	static const int SpiderDeathMedium = 600;
	static const int SpiderDistanceMedium = 100;
	static const int SpiderDeathFar = 300;
	static const int SpiderDistanceFar = 100;

	static const int MushroomDeath = 1;
	static const int PoisonMushroomDeath = 1;
	static const int MushroomRegen = 5;

	std::queue<CmdScore*> QueueCmds;

	static ScoreManager* ptrInstance;

	static ScoreManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ScoreManager;
		return *ptrInstance;
	}

	ScoreManager();
	ScoreManager(ScoreManager& other) = delete;
	ScoreManager& operator=(ScoreManager& other) = delete;
	~ScoreManager() = default;

	void privProcessScore();

public:
	enum class ScoreEvents
	{
		FleaKilled,
		ScorpionKilled,
		CentipedeHeadKilled,
		CentipedeBodyKilled,
		CloseSpiderKilled,
		MediumSpiderKilled,
		FarSpiderKilled,
		MushroomKilled,
		PoisonMushroomKilled,
		MushroomRegen,
		LevelFinished
	};

	static void AddScore(int val);

	static CmdScore* GetScoreCommand(ScoreEvents ev);

	static void SendScoreCmd(CmdScore* c);
	static void ProcessScores() { Instance().privProcessScore(); };

	static void Terminate();
};

#endif _ScoreManager
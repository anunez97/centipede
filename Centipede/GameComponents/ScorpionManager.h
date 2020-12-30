// Scorpion Manager

#ifndef _ScorpionManager
#define _ScorpionManager

#include "TEAL/CommonElements.h"

class Scorpion;

class ScorpionManager : public GameObject
{
private:
	static ScorpionManager* ptrInstance;

	static ScorpionManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ScorpionManager;
		return *ptrInstance;
	}

	ScorpionManager();
	ScorpionManager(ScorpionManager& other) = delete;
	ScorpionManager& operator=(ScorpionManager& other) = delete;
	~ScorpionManager() = default;

	void privSpawnScorpion();
	void privSetScorpionSpawn(bool s);
	void privSetScorpionFrequency(float val);
	void privReduceScorpionCount();
	void privReset();
	void privTerminate();

	float ScorpionFrequency;
	int ScorpionCount;
	bool ScorpionSpawning;

	virtual void Alarm0();

	Scorpion* pScorpion;

public:
	static void SpawnScorpion() { Instance().privSpawnScorpion(); }
	static void SetScorpionSpawn(bool s) { Instance().privSetScorpionSpawn(s); }
	static void SetScorpionFrequency(float val) { Instance().privSetScorpionFrequency(val); }
	static void ReduceScorpionCount() { Instance().privReduceScorpionCount(); }
	static void Reset() { Instance().privReset(); }
	static void PoisonMushroom(int col, int row);
	static void Terminate() { Instance().privTerminate(); };

};

#endif _ScorpionManager
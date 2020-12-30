// Flea Manager

#ifndef _FleaManager
#define _FleaManager

#include "TEAL/CommonElements.h"

class MushroomField;
class Flea;
class CmdSound;

class FleaManager
{
private:
	static FleaManager* ptrInstance;

	static FleaManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new FleaManager;
		return *ptrInstance;
	}

	FleaManager();
	FleaManager(FleaManager& other) = delete;
	FleaManager& operator=(FleaManager& other) = delete;
	~FleaManager() = default;

	void privSpawnFlea(int count, MushroomField* mf);
	void privSetFleaSpawn(bool s);
	void privSetMushroomCountTrigger(int count); // Number of mushrooms in player area for flea to spawn
	void privReduceFleaCount();
	void privReset();

	int FleaCount;
	int MushroomCount;
	bool FleaSpawning;
	Flea* pFlea;
	CmdSound* pSound;

public:
	static void SpawnFlea(int count, MushroomField* mf) { Instance().privSpawnFlea(count, mf); }
	static void SetFleaSpawn(bool s) { Instance().privSetFleaSpawn(s); }
	static void SetMushroomCountTrigger(int count) { Instance().privSetMushroomCountTrigger(count); }
	static void ReduceFleaCount() { Instance().privReduceFleaCount(); }
	static void Reset() { Instance().privReset(); }

	static void Terminate();

};

#endif _FleaManager
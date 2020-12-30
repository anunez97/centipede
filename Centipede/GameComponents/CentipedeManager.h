// Centipede Manager

#ifndef _CentipedeManager
#define _CentipedeManager

#include "TEAL/CommonElements.h"

class MushroomField;
class CentipedeHead;
class CmdSound;

class CentipedeManager
{
private:
	static CentipedeManager* ptrInstance;

	static CentipedeManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeManager;
		return *ptrInstance;
	}

	CentipedeManager();
	CentipedeManager(CentipedeManager& other) = delete;
	CentipedeManager& operator=(CentipedeManager& other) = delete;
	~CentipedeManager() = default;
	
	void privSpawnCentipede(int bodyCount, MushroomField* mf);
	void privSetCentipedeSpeed(int speed);
	void privSpawnSoloHead();
	void privSetSoloHeadCount(int count);
	void privSetSoloHeadSpeed(int speed);
	void privStopMovement();
	void privReset();
	void privAddCentipede(CentipedeHead* c);
	void privRemoveCentipede(CentipedeHead* c);
	void privTerminate();

	int CentipedeSpeed;
	int CentipedeHeadCount;
	int SoloHeadCount;
	int SoloHeadSpeed;
	CmdSound* pSound;

	std::list<CentipedeHead*> centiHeads;


public:
	static void SpawnCentipede(int bodyCount, MushroomField* mf) { Instance().privSpawnCentipede(bodyCount, mf); }
	static void SetCentipedeSpeed(int speed) { Instance().privSetCentipedeSpeed(speed); }
	static void SpawnSoloHead() { Instance().privSpawnSoloHead(); }
	static void SetSoloHeadCount(int count) { Instance().privSetSoloHeadCount(count); }
	static void SetSoloHeadSpeed(int speed) { Instance().privSetSoloHeadSpeed(speed); }

	static void ReduceHeadCount();
	static void IncreaseHeadCount();
	static void StopMovement() { Instance().privStopMovement(); }
	static void Reset() { Instance().privReset(); }
	static void AddCentipede(CentipedeHead* c) { Instance().privAddCentipede(c); }
	static void RemoveCentipede(CentipedeHead* c) { Instance().privRemoveCentipede(c); }

	static void Terminate() { Instance().privTerminate(); }
};

#endif _CentipedeManager
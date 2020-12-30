// Critter Manager

#ifndef _CritterManager
#define _CritterManager

#include "TEAL/CommonElements.h"

class MushroomField;
class Scorpion;
class Spider;
class Flea;
class CentipedeHead;
class CentipedeBody;

class CritterManager
{
public:
	static void SpawnSpider() { Instance().privSpawnSpider(); }
	static void SpawnScorpion() { Instance().privSpawnScorpion(); }
	static void SpawnFlea(int count, MushroomField* mf) { Instance().privSpawnFlea(count, mf); }
	static void SpawnCentipedeHead(sf::Vector2f pos, int bodyCnt, MushroomField* mfield) 
	{ Instance().privSpawnCentipedeHead(pos, bodyCnt, mfield); }

	// Flea
	static void SetFleaSpawn(bool b) { Instance().privSetFleaSpawn(b); }
	static void SetMushroomCnt(int count) { Instance().privSetMushroomCnt(count); }
	static void ReduceFleaCount() { Instance().privReduceFleaCount(); }

	// Scorpion
	static void SetScorpionSpawn(bool b) { Instance().privSetScorpionSpawn(b); }
	//static void SetScorpionFrequency(float val) { Instance().privSetScorpionFrequency(val); }
	static void ReduceScorpionCount() { Instance().privReduceScorpionCount(); }

	// Spider
	static void SetSpiderSpawn(bool b) { Instance().privSetSpiderSpawn(b); }
	//static void SetSpiderFrequency(float val) { Instance().privSetSpiderFrequency(val); }
	static void SetSpiderSpeed(int val) { Instance().privSetSpiderSpeed(val); }
	static void ReduceSpiderCount() { Instance().privReduceSpiderCount(); }

	static void Terminate();

private:
	static CritterManager* ptrInstance;

	static CritterManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CritterManager;
		return *ptrInstance;
	}

	CritterManager();
	CritterManager(CritterManager& other) = delete;
	CritterManager& operator=(CritterManager& other) = delete;
	~CritterManager() = default;

	void privSpawnSpider();
	void privSpawnScorpion();
	void privSpawnFlea(int count, MushroomField* mf);
	void privSpawnCentipedeHead(sf::Vector2f pos, int bodyCnt, MushroomField* mfield);

	void privSetFleaSpawn(bool s);
	void privSetMushroomCnt(int count);
	void privReduceFleaCount();

	void privSetScorpionSpawn(bool b);
	void privReduceScorpionCount();

	void privSetSpiderSpawn(bool b);
	void privSetSpiderSpeed(int val);
	void privReduceSpiderCount();

	sf::Vector2f Pos;
	bool FleaSpawn;
	int FleaMushroomCnt;
	int FleaCount;

	bool SpiderSpawn;
	int SpiderSpeed;
	int SpiderCount;

	bool ScorpionSpawn;
	int ScorpionCount;
	
};

#endif _CritterManager
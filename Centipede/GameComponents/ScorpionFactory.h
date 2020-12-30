// Scorpion Factory

#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "TEAL/CommonElements.h"
#include "ScorpionObjectPool.h"

class GameObject;
class CmdScore;
class CmdSound;

class ScorpionFactory
{
private:
	// Singleton
	static ScorpionFactory* ptrInstance;

	ScorpionFactory();
	ScorpionFactory(const ScorpionFactory&) = delete;
	ScorpionFactory& operator=(const ScorpionFactory&) = delete;
	~ScorpionFactory() = default;

	static ScorpionFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ScorpionFactory();
		return *ptrInstance;
	}

	ScorpionObjectPool ScorpionPool;
	CmdScore* pDeath;
	CmdSound* pSound;

	Scorpion* privCreateScorpion(sf::Vector2f pos);
	void privRecycleScorpion(GameObject *b);
	void privTerminate();

public:
	static Scorpion* CreateScorpion(sf::Vector2f pos) { return Instance().privCreateScorpion(pos); }
	static void RecycleScorpion(GameObject* b) { Instance().privRecycleScorpion(b); }
	static void ScorpionDeath();
	static void Terminate() { Instance().privTerminate(); };

};

#endif _ScorpionFactory
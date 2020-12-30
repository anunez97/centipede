// Flea Factory

#ifndef _FleaFactory
#define _FleaFactory

#include "TEAL/CommonElements.h"
#include "FleaObjectPool.h"

class GameObject;
class MushroomField;
class CmdScore;

class FleaFactory
{
private:
	// Singleton
	static FleaFactory* ptrInstance;

	FleaFactory();
	FleaFactory(const FleaFactory&) = delete;
	FleaFactory& operator=(const FleaFactory&) = delete;
	~FleaFactory() = default;

	static FleaFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new FleaFactory();
		return *ptrInstance;
	}

	FleaObjectPool FleaPool;
	CmdScore* pDeath;

	Flea* privCreateFlea(sf::Vector2f pos, MushroomField* mf);
	void privRecycleFlea(GameObject* b);
	void privTerminate();

public:
	static Flea* CreateFlea(sf::Vector2f pos, MushroomField* mf) { return Instance().privCreateFlea(pos, mf); }
	static void RecycleFlea(GameObject* b) { Instance().privRecycleFlea(b); }

	static void Terminate() { Instance().privTerminate(); };

};

#endif _FleaFactory
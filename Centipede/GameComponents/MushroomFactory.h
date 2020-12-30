// Mushroom Factory

#ifndef _MushroomFactory
#define _MushroomFactory

#include "TEAL/CommonElements.h"
#include "MushroomObjectPool.h"

class GameObject;
class MushroomField;
class CmdScore;

class MushroomFactory
{
private:
	// Singleton
	static MushroomFactory* ptrInstance;

	MushroomFactory();
	MushroomFactory(const MushroomFactory&) = delete;
	MushroomFactory& operator=(const MushroomFactory&) = delete;
	~MushroomFactory() = default;

	static MushroomFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new MushroomFactory();
		return *ptrInstance;
	}

	MushroomObjectPool MushroomPool;
	CmdScore* pNormalMushroomDeath;
	CmdScore* pPoisonMushroomDeath;

	Mushroom* privCreateMushroom(sf::Vector2f pos, int c, int r, MushroomField*mf);
	void privRecycleMushroom(GameObject* b);
	void privTerminate();

public:
	static Mushroom* CreateMushroom(sf::Vector2f pos, int c, int r, MushroomField* mf) { return Instance().privCreateMushroom(pos, c, r, mf); }
	static void RecycleMushroom(GameObject* b) { Instance().privRecycleMushroom(b); }

	static void Terminate() { Instance().privTerminate(); };

};

#endif _MushroomFactory
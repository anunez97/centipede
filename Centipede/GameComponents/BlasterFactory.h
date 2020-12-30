// Blaster Factory

#ifndef _BlasterFactory
#define _BlasterFactory

#include "TEAL/CommonElements.h"
#include "BlasterObjectPool.h"

class GameObject;
class Player;
class CmdSound;

class BlasterFactory
{
private:
	// Singleton
	static BlasterFactory* ptrInstance;

	BlasterFactory();
	BlasterFactory(const BlasterFactory&) = delete;
	BlasterFactory& operator=(const BlasterFactory&) = delete;
	~BlasterFactory() = default;

	static BlasterFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new BlasterFactory();
		return *ptrInstance;
	}

	BlasterObjectPool BlasterPool;

	Blaster* privCreateBlaster(sf::Vector2f pos, Player* pm);
	void privRecycleBlaster(GameObject* b);
	void privTerminate();

	CmdSound* pSound;

public:
	static Blaster* CreateBlaster(sf::Vector2f pos, Player* pm) { return Instance().privCreateBlaster(pos, pm); }
	static void RecycleBlaster(GameObject* b) { Instance().privRecycleBlaster(b); }
	static void PlayerDeath();
	static void Terminate() { Instance().privTerminate(); }

};

#endif _BlasterFactory
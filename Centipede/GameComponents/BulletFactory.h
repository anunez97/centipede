// Bullet Factory

#ifndef _BulletFactory
#define _BulletFactory

#include "TEAL/CommonElements.h"
#include "BulletObjectPool.h"

class GameObject;
class Blaster;
class CmdSound;

class BulletFactory
{
private:
	// Singleton
	static BulletFactory* ptrInstance;

	BulletFactory();
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory() = default;

	static BulletFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new BulletFactory();
		return *ptrInstance;
	}

	BulletObjectPool BulletPool;

	Bullet* privCreateBullet(sf::Vector2f pos, Blaster* b);
	void privRecycleBullet(GameObject* b);
	void privTerminate();

	CmdSound* pSound;

public:
	static Bullet* CreateBullet(sf::Vector2f pos, Blaster* b) { return Instance().privCreateBullet(pos, b); }
	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); }

	static void Terminate() { Instance().privTerminate(); };

};

#endif _BulletFactory
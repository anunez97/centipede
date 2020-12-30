// Explosion Factory

#ifndef _ExplosionFactory
#define _ExplosionFactory

#include "TEAL/CommonElements.h"
#include "ExplosionObjectPool.h"

class ExplosionFactory
{
private:
	static ExplosionFactory* ptrInstance;

	static ExplosionFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ExplosionFactory;
		return *ptrInstance;
	}

	ExplosionFactory();
	ExplosionFactory(ExplosionFactory& other) = delete;
	ExplosionFactory& operator=(ExplosionFactory& other) = delete;
	~ExplosionFactory() = default;

	void privCreateExplosion(sf::Vector2f pos);
	void privRecycleExplosion(GameObject* b);

	ExplosionObjectPool ExplosionPool;

public:
	static void CreateExplosion(sf::Vector2f pos) { Instance().privCreateExplosion(pos); }
	static void RecycleExplosion(GameObject* e) { Instance().privRecycleExplosion(e); }

	static void Terminate();
};

#endif _ExplosionFactory
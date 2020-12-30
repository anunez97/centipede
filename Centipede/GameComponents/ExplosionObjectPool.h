// Explosion Object Pool

#ifndef _ExplosionObjectPool
#define _ExplosionObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Explosion;

class ExplosionObjectPool
{
public:
	ExplosionObjectPool();
	ExplosionObjectPool(ExplosionObjectPool& other) = delete;
	ExplosionObjectPool& operator=(ExplosionObjectPool& other) = delete;
	~ExplosionObjectPool();

	Explosion* getExplosion();
	void returnExplosion(Explosion*);

private:
	std::stack<Explosion*> recycledExplosions;
};

#endif _ExplosionObjectPool

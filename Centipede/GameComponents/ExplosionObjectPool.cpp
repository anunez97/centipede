// Explosion Object Pool

#include "ExplosionObjectPool.h"
#include "Explosion.h"

ExplosionObjectPool::ExplosionObjectPool()
{

}

ExplosionObjectPool::~ExplosionObjectPool()
{
	while (!recycledExplosions.empty())
	{
		delete recycledExplosions.top();
		recycledExplosions.pop();
	}
}

Explosion* ExplosionObjectPool::getExplosion()
{
	Explosion* e;

	if (recycledExplosions.empty())
	{
		e = new Explosion();
	}
	else
	{
		e = recycledExplosions.top();
		recycledExplosions.pop();

		e->RegisterToCurrentScene();
	}

	return e;
}

void ExplosionObjectPool::returnExplosion(Explosion* m)
{
	recycledExplosions.push(static_cast<Explosion*>(m));
}
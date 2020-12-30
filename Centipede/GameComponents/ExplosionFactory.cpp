// Explosion Factory

#include "ExplosionFactory.h"
#include "ExplosionObjectPool.h"
#include "Explosion.h"

ExplosionFactory* ExplosionFactory::ptrInstance = nullptr;

ExplosionFactory::ExplosionFactory()
{

}

void ExplosionFactory::privCreateExplosion(sf::Vector2f pos)
{
	Explosion* e = ExplosionPool.getExplosion();

	e->SetExternalManagement(RecycleExplosion);

	e->Initialize(pos);

}

void ExplosionFactory::privRecycleExplosion(GameObject* ob)
{
	ExplosionPool.returnExplosion(static_cast<Explosion*>(ob));
}

void ExplosionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
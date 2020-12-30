// Mushroom Object Pool

#include "MushroomObjectPool.h"
#include "Mushroom.h"

MushroomObjectPool::MushroomObjectPool()
{

}

MushroomObjectPool::~MushroomObjectPool()
{
	while (!recycledMushrooms.empty())
	{
		delete recycledMushrooms.top();
		recycledMushrooms.pop();
	}
}

Mushroom* MushroomObjectPool::getMushroom()
{
	Mushroom* m;

	if (recycledMushrooms.empty())
	{
		m = new Mushroom();
	}
	else
	{
		m = recycledMushrooms.top();
		recycledMushrooms.pop();

		m->RegisterToCurrentScene();
	}

	return m;
}

void MushroomObjectPool::returnMushroom(Mushroom* m)
{
	recycledMushrooms.push(static_cast<Mushroom*>(m));
}
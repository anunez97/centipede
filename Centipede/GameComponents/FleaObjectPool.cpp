// Flea Object Pool

#include "FleaObjectPool.h"
#include "Flea.h"

FleaObjectPool::FleaObjectPool()
{

}

FleaObjectPool::~FleaObjectPool()
{
	while (!recycledFleas.empty())
	{
		delete recycledFleas.top();
		recycledFleas.pop();
	}
}

Flea* FleaObjectPool::getFlea()
{
	Flea* f;

	if (recycledFleas.empty())
	{
		f = new Flea();
	}
	else
	{
		f = recycledFleas.top();
		recycledFleas.pop();

		f->RegisterToCurrentScene();
	}

	return f;
}

void FleaObjectPool::returnFlea(Flea* f)
{
	recycledFleas.push(static_cast<Flea*>(f));
}
// Blaster Object Pool

#include "BlasterObjectPool.h"
#include "Blaster.h"

BlasterObjectPool::BlasterObjectPool()
{

}

BlasterObjectPool::~BlasterObjectPool()
{
	while (!recycledBlasters.empty())
	{
		delete recycledBlasters.top();
		recycledBlasters.pop();
	}
}

Blaster* BlasterObjectPool::getBlaster()
{
	Blaster* b;

	if (recycledBlasters.empty())
	{
		b = new Blaster();
	}
	else
	{
		b = recycledBlasters.top();
		recycledBlasters.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void BlasterObjectPool::returnBlaster(Blaster* f)
{
	recycledBlasters.push(static_cast<Blaster*>(f));
}
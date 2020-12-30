// Bullet Object Pool

#include "BulletObjectPool.h"
#include "Bullet.h"

BulletObjectPool::BulletObjectPool()
{

}

BulletObjectPool::~BulletObjectPool()
{
	while (!recycledBullets.empty())
	{
		delete recycledBullets.top();
		recycledBullets.pop();
	}
}

Bullet* BulletObjectPool::getBullet()
{
	Bullet* b;

	if (recycledBullets.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet"); // For illustration purposes
		b = new Bullet();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes
		b = recycledBullets.top();
		recycledBullets.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletObjectPool::returnBullet(Bullet* f)
{
	recycledBullets.push(static_cast<Bullet*>(f));
	//ConsoleMsg::WriteLine("Recycled Bullet Stack Size: " + Tools::ToString(recycledBullets.size()));
}
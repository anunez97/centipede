// Bullet Object Pool

#ifndef _BulletObjectPool
#define _BulletObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Bullet;

class BulletObjectPool
{
public:
	BulletObjectPool();
	BulletObjectPool(BulletObjectPool& other) = delete;
	BulletObjectPool& operator=(BulletObjectPool& other) = delete;
	~BulletObjectPool();

	Bullet* getBullet();
	void returnBullet(Bullet*);

private:
	std::stack<Bullet*> recycledBullets;
};

#endif _BulletObjectPool
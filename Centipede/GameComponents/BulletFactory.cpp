// Bullet Factory

#include "BulletFactory.h"
#include "BulletObjectPool.h"
#include "Bullet.h"
#include "SoundManager.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

BulletFactory::BulletFactory()
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::BulletSound);
}

Bullet* BulletFactory::privCreateBullet(sf::Vector2f pos, Blaster* bl)
{
	Bullet* b = BulletPool.getBullet();

	b->SetExternalManagement(RecycleBullet);

	b->Initialize(pos, bl);

	SoundManager::SendPlayCmd(pSound);

	return b;
}

void BulletFactory::privRecycleBullet(GameObject* ob)
{
	BulletPool.returnBullet(static_cast<Bullet*>(ob));
}

void BulletFactory::privTerminate()
{
	delete pSound;
	delete ptrInstance;
	ptrInstance = nullptr;
}
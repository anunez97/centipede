// Blaster Factory

#include "BlasterFactory.h"
#include "BlasterObjectPool.h"
#include "Blaster.h"
#include "SoundManager.h"

BlasterFactory* BlasterFactory::ptrInstance = nullptr;

BlasterFactory::BlasterFactory()
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::PlayerDeathSound);
}

Blaster* BlasterFactory::privCreateBlaster(sf::Vector2f pos, Player* p)
{
	Blaster* b = BlasterPool.getBlaster();

	b->SetExternalManagement(RecycleBlaster);

	b->Initialize(pos, p);

	return b;
}

void BlasterFactory::privRecycleBlaster(GameObject* ob)
{
	BlasterPool.returnBlaster(static_cast<Blaster*>(ob));
}

void BlasterFactory::PlayerDeath()
{
	SoundManager::SendPlayCmd(Instance().pSound);
}

void BlasterFactory::privTerminate()
{
	delete pSound;
	delete ptrInstance;
	ptrInstance = nullptr;
}
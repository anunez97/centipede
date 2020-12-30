// Scorpion Factory

#include "ScorpionFactory.h"
#include "ScorpionObjectPool.h"
#include "Scorpion.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "SoundManager.h"

ScorpionFactory* ScorpionFactory::ptrInstance = nullptr;

ScorpionFactory::ScorpionFactory()
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled);
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::ScorpionSound);
}

Scorpion* ScorpionFactory::privCreateScorpion(sf::Vector2f pos)
{
	Scorpion* s = ScorpionPool.getScorpion();

	s->SetExternalManagement(RecycleScorpion);

	s->Initialize(pos, pDeath);

	SoundManager::SendPlayCmd(pSound);

	return s;
}

void ScorpionFactory::privRecycleScorpion(GameObject* ob)
{
	SoundManager::SendStopCmd(pSound);
	ScorpionPool.returnScorpion(static_cast<Scorpion*>(ob));
}

void ScorpionFactory::ScorpionDeath()
{
	SoundManager::SendStopCmd(Instance().pSound);
}

void ScorpionFactory::privTerminate()
{
	delete pDeath;
	delete pSound;
	delete ptrInstance;
	ptrInstance = nullptr;
}
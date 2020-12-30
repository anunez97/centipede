// Scorpion Object Pool

#include "ScorpionObjectPool.h"
#include "Scorpion.h"

ScorpionObjectPool::ScorpionObjectPool()
{

}

ScorpionObjectPool::~ScorpionObjectPool()
{
	while (!recycledScorpions.empty())
	{
		delete recycledScorpions.top();
		recycledScorpions.pop();
	}
}

Scorpion* ScorpionObjectPool::getScorpion()
{
	Scorpion* s;

	if (recycledScorpions.empty())
	{
		//ConsoleMsg::WriteLine("New Scorpion"); // For illustration purposes
		s = new Scorpion();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Scorpion"); // For illustration purposes
		s = recycledScorpions.top();
		recycledScorpions.pop();

		s->RegisterToCurrentScene();
	}

	return s;
}

void ScorpionObjectPool::returnScorpion(Scorpion* s)
{
	recycledScorpions.push(static_cast<Scorpion*>(s));
	//ConsoleMsg::WriteLine("Recycled Scorpion Stack Size: " + Tools::ToString(recycledScorpions.size()));
}
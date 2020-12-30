// Scorpion Object Pool

#ifndef _ScorpionObjectPool
#define _ScorpionObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Scorpion;

class ScorpionObjectPool
{
public:
	ScorpionObjectPool();
	ScorpionObjectPool(ScorpionObjectPool& other) = delete;
	ScorpionObjectPool& operator=(ScorpionObjectPool& other) = delete;
	~ScorpionObjectPool();

	Scorpion* getScorpion();
	void returnScorpion(Scorpion*);

private:
	std::stack<Scorpion*> recycledScorpions;
};

#endif _ScorpionObjectPool

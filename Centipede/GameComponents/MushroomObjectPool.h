// Mushroom Object Pool

#ifndef _MushroomObjectPool
#define _MushroomObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Mushroom;

class MushroomObjectPool
{
public:
	MushroomObjectPool();
	MushroomObjectPool(MushroomObjectPool& other) = delete;
	MushroomObjectPool& operator=(MushroomObjectPool& other) = delete;
	~MushroomObjectPool();

	Mushroom* getMushroom();
	void returnMushroom(Mushroom*);

private:
	std::stack<Mushroom*> recycledMushrooms;
};

#endif _MushroomObjectPool

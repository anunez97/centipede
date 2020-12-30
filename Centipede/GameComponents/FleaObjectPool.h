// Flea Object Pool

#ifndef _FleaObjectPool
#define _FleaObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Flea;

class FleaObjectPool
{
public:
	FleaObjectPool();
	FleaObjectPool(FleaObjectPool& other) = delete;
	FleaObjectPool& operator=(FleaObjectPool& other) = delete;
	~FleaObjectPool();

	Flea* getFlea();
	void returnFlea(Flea*);

private:
	std::stack<Flea*> recycledFleas;
};

#endif _FleaObjectPool
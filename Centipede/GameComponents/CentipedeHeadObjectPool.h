// CentipedeHead Object Pool

#ifndef _CentipedeHeadObjectPool
#define _CentipedeHeadObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class CentipedeHead;

class CentipedeHeadObjectPool
{
public:
	CentipedeHeadObjectPool();
	CentipedeHeadObjectPool(CentipedeHeadObjectPool& other) = delete;
	CentipedeHeadObjectPool& operator=(CentipedeHeadObjectPool& other) = delete;
	~CentipedeHeadObjectPool();

	CentipedeHead* getCentipedeHead();
	void returnCentipedeHead(CentipedeHead*);

private:
	std::stack<CentipedeHead*> recycledCentipedeHeads;
};

#endif _CentipedeHeadObjectPool
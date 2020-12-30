// Centipede Body Object Pool

#ifndef _CentipedeBodyObjectPool
#define _CentipedeBodyObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class CentipedeBody;

class CentipedeBodyObjectPool
{
public:
	CentipedeBodyObjectPool();
	CentipedeBodyObjectPool(CentipedeBodyObjectPool& other) = delete;
	CentipedeBodyObjectPool& operator=(CentipedeBodyObjectPool& other) = delete;
	~CentipedeBodyObjectPool();

	CentipedeBody* getCentipedeBody();
	void returnCentipedeBody(CentipedeBody*);

private:
	std::stack<CentipedeBody*> recycledCentipedeBodies;
};

#endif _CentipedeBodyObjectPool
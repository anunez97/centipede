// Centipede Body Object Pool

#include "CentipedeBodyObjectPool.h"
#include "CentipedeBody.h"

CentipedeBodyObjectPool::CentipedeBodyObjectPool()
{

}

CentipedeBodyObjectPool::~CentipedeBodyObjectPool()
{
	while (!recycledCentipedeBodies.empty())
	{
		delete recycledCentipedeBodies.top();
		recycledCentipedeBodies.pop();
	}
}

CentipedeBody* CentipedeBodyObjectPool::getCentipedeBody()
{
	CentipedeBody* c;

	if (recycledCentipedeBodies.empty())
	{
		c = new CentipedeBody();
	}
	else
	{
		c = recycledCentipedeBodies.top();
		recycledCentipedeBodies.pop();

		c->RegisterToCurrentScene();
	}

	return c;
}

void CentipedeBodyObjectPool::returnCentipedeBody(CentipedeBody* f)
{
	recycledCentipedeBodies.push(static_cast<CentipedeBody*>(f));
	//ConsoleMsg::WriteLine("Recycled CentipedeHead Stack Size: " + Tools::ToString(recycledCentipedeBodies.size()));
}
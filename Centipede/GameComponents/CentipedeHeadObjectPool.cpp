// CentipedeHead Object Pool

#include "CentipedeHeadObjectPool.h"
#include "CentipedeHead.h"

CentipedeHeadObjectPool::CentipedeHeadObjectPool()
{

}

CentipedeHeadObjectPool::~CentipedeHeadObjectPool()
{
	while (!recycledCentipedeHeads.empty())
	{
		delete recycledCentipedeHeads.top();
		recycledCentipedeHeads.pop();
	}
}

CentipedeHead* CentipedeHeadObjectPool::getCentipedeHead()
{
	CentipedeHead* c;

	if (recycledCentipedeHeads.empty())
	{
		//ConsoleMsg::WriteLine("New CentipedeHead"); // For illustration purposes
		c = new CentipedeHead();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled CentipedeHead"); // For illustration purposes
		c = recycledCentipedeHeads.top();
		recycledCentipedeHeads.pop();

		c->RegisterToCurrentScene();
	}

	return c;
}

void CentipedeHeadObjectPool::returnCentipedeHead(CentipedeHead* f)
{
	recycledCentipedeHeads.push(static_cast<CentipedeHead*>(f));
	//ConsoleMsg::WriteLine("Recycled CentipedeHead Stack Size: " + Tools::ToString(recycledCentipedeHeads.size()));
}
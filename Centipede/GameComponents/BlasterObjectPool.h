// Blaster Object Pool

#ifndef _BlasterObjectPool
#define _BlasterObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Blaster;

class BlasterObjectPool
{
public:
	BlasterObjectPool();
	BlasterObjectPool(BlasterObjectPool& other) = delete;
	BlasterObjectPool& operator=(BlasterObjectPool& other) = delete;
	~BlasterObjectPool();

	Blaster* getBlaster();
	void returnBlaster(Blaster*);

private:
	std::stack<Blaster*> recycledBlasters;
};

#endif _BlasterObjectPool
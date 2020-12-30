// Controller

#ifndef _Controller
#define _Controller

#include "TEAL/CommonElements.h"

class Blaster;

class Controller : public GameObject
{
public:
	Controller() {};
	Controller(Controller& other) = delete;
	Controller& operator=(Controller& other) = delete;
	~Controller() = default;

	virtual void SetBlaster(Blaster*) {};
	virtual void Disable() {};
	virtual void Enable() {};

private:

};


#endif _Controller
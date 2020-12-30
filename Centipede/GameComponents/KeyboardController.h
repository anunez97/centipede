// Keyboard Controller

#ifndef _KeyboardController
#define _KeyboardController

#include "TEAL/CommonElements.h"
#include "Controller.h"

class KeyboardController : public Controller
{
public:
	KeyboardController();
	KeyboardController(KeyboardController& other) = delete;
	KeyboardController& operator=(KeyboardController& other) = delete;
	~KeyboardController();

	void SetBlaster(Blaster*);
	void Disable();
	void Enable();
	virtual void Update();
	virtual void Destroy();

private:
	Blaster* pBlaster;
};

#endif _KeyboardController
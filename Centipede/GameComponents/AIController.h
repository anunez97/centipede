// AI Controller

#ifndef _AIController
#define _AIController

#include "Controller.h"

class AttractorMoveState;

class AIController : public Controller
{
public:
	AIController();
	AIController(AIController& other) = delete;
	AIController& operator=(AIController& other) = delete;
	~AIController();

	void SetBlaster(Blaster* b);
	void Disable();
	void Enable();
	virtual void Update();
	virtual void Destroy();

private:
	Blaster* pBlaster;
	const AttractorMoveState* pMoveState;
	bool isEnabled;
	int index;
};

#endif _AIController
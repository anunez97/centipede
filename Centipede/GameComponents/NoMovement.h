// No Movement

#ifndef _NoMovement
#define _NoMovement

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class NoMovement : public MoveState
{
public:
	NoMovement();
	virtual const MoveState* GetNextState(CentipedeHead*) const override;
	virtual void Show() const override;

private:
	int frameCount;
};

#endif _NoMovement

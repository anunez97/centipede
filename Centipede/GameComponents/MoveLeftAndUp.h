// Move Left And Up

#ifndef _MoveLeftAndUp
#define _MoveLeftAndUp

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class MoveLeftAndUp : public MoveState
{
public:
	MoveLeftAndUp();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;

private:
	int frameCount;
};

#endif _MoveLeftAndDown
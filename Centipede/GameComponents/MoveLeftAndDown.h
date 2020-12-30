// Move Left And Down

#ifndef _MoveLeftAndDown
#define _MoveLeftAndDown

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class MoveLeftAndDown : public MoveState
{
public:
	MoveLeftAndDown();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;

private:
	int frameCount;

};

#endif _MoveLeftAndDown
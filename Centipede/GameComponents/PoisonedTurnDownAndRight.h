// Poisoned Turn Down And Right

#ifndef _PoisonedTurnDownAndRight
#define _PoisonedTurnDownAndRight

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class PoisonedTurnDownAndRight : public MoveState
{
public:
	PoisonedTurnDownAndRight();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;

private:
	int frameCount;
};

#endif _PoisonedTurnDownAndRight
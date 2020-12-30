// Poisoned Turn Down And Left

#ifndef _PoisonedTurnDownAndLeft
#define _PoisonedTurnDownAndLeft

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class PoisonedTurnDownAndLeft : public MoveState
{
public:
	PoisonedTurnDownAndLeft();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;

private:
	int frameCount;
};

#endif _PoisonedTurnDownAndLeft

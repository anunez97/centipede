// Move Right And Down

#ifndef _MoveRightAndDown
#define _MoveRightAndDown

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class MoveRightAndDown : public MoveState
{
public:
	MoveRightAndDown();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;

private:
	int frameCount;
};

#endif _MoveRightAndDown
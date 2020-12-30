// Move Right And Up

#ifndef _MoveRightAndUp
#define _MoveRightAndUp

#include "TEAL/CommonElements.h"
#include "MoveState.h"

class MoveRightAndUp : public MoveState
{
public:
	MoveRightAndUp();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;

private:
	int frameCount;
};

#endif _MoveRightAndUp

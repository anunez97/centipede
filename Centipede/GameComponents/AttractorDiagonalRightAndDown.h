// AttractorDiagonalRightAndDown

#ifndef _AttractorDiagonalRightAndDown
#define _AttractorDiagonalRightAndDown

#include "AttractorMoveState.h"

class Blaster;

class AttractorDiagonalRightAndDown: public AttractorMoveState
{
public:
	AttractorDiagonalRightAndDown();
	virtual const AttractorMoveState* GetNextState(Blaster* b) const override;
	virtual void Show() const override;
};

#endif _AttractorDiagonalRightAndDown
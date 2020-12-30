// AttractorDiagonalRightAndDown

#ifndef _AttractorDiagonalRightAndUp
#define _AttractorDiagonalRightAndUp

#include "AttractorMoveState.h"

class Blaster;

class AttractorDiagonalRightAndUp : public AttractorMoveState
{
public:
	AttractorDiagonalRightAndUp();
	virtual const AttractorMoveState* GetNextState(Blaster* b) const override;
	virtual void Show() const override;
};

#endif _AttractorDiagonalRightAndUp
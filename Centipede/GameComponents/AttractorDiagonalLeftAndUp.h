// AttractorDiagonalLeftAndUp

#ifndef _AttractorDiagonalLeftAndUp
#define _AttractorDiagonalLeftAndUp

#include "AttractorMoveState.h"

class Blaster;

class AttractorDiagonalLeftAndUp : public AttractorMoveState
{
public:
	AttractorDiagonalLeftAndUp();
	virtual const AttractorMoveState* GetNextState(Blaster* b) const override;
	virtual void Show() const override;
};

#endif _AttractorDiagonalLeftAndUp
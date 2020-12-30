// AttractorDiagonalLeftAndDown

#ifndef _AttractorDiagonalLeftAndDown
#define _AttractorDiagonalLeftAndDown

#include "AttractorMoveState.h"

class Blaster;

class AttractorDiagonalLeftAndDown : public AttractorMoveState
{
public:
	AttractorDiagonalLeftAndDown();
	virtual const AttractorMoveState* GetNextState(Blaster* b) const override;
	virtual void Show() const override;
};

#endif _AttractorDiagonalLeftAndDown
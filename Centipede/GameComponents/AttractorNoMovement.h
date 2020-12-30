// Attractor No Movement

#ifndef _AttractorNoMovement
#define _AttractorNoMovement

#include "AttractorMoveState.h"

class Blaster;

class AttractorNoMovement : public AttractorMoveState
{
public:
	AttractorNoMovement();
	virtual const AttractorMoveState* GetNextState(Blaster* b) const override;
	virtual void Show() const override;
};

#endif _AttractorNoMovement
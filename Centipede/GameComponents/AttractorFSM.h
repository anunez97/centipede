// Attractor FSM

#ifndef _AttractorFSM
#define _AttractorFSM

#include "AttractorDiagonalLeftAndDown.h"
#include "AttractorDiagonalLeftAndUp.h"
#include "AttractorDiagonalRightAndDown.h"
#include "AttractorDiagonalRightAndUp.h"
#include "AttractorNoMovement.h"

class AttractorFSM
{
public:
	static const AttractorDiagonalLeftAndDown StateDiagonalLeftAndDown;
	static const AttractorDiagonalLeftAndUp StateDiagonalLeftAndUp;
	static const AttractorDiagonalRightAndDown StateDiagonalRightAndDown;
	static const AttractorDiagonalRightAndUp StateDiagonalRightAndUp;
	static const AttractorNoMovement StateNoMovement;
};

#endif _AttractorFSM
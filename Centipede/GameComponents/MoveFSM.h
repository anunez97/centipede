// Move Finite State Machine

#ifndef _MoveFSM
#define _MoveFSM

#include "TEAL/CommonElements.h"
#include "MoveLeftAndDown.h"
#include "MoveLeftAndUp.h"
#include "MoveRightAndDown.h"
#include "MoveRightAndUp.h"
#include "TurnDownAndLeft.h"
#include "TurnDownAndRight.h"
#include "TurnUpAndLeft.h"
#include "TurnUpAndRight.h"
#include "PoisonedTurnDownAndLeft.h"
#include "PoisonedTurnDownAndRight.h"
#include "NoMovement.h"

class MoveFSM
{
public:
	static const MoveLeftAndDown StateMoveLeftAndDown;
	static const MoveLeftAndUp StateMoveLeftAndUp;
	static const MoveRightAndDown StateMoveRightAndDown;
	static const MoveRightAndUp StateMoveRightAndUp;
	static const TurnDownAndLeft StateTurnDownAndLeft;
	static const TurnDownAndRight StateTurnDownAndRight;
	static const TurnUpAndLeft StateTurnUpAndLeft;
	static const TurnUpAndRight StateTurnUpAndRight;
	static const PoisonedTurnDownAndLeft StatePoisonedTurnDownAndLeft;
	static const PoisonedTurnDownAndRight StatePoisonedTurnDownAndRight;
	static const NoMovement StateNoMovement;
};

#endif _MoveFSM
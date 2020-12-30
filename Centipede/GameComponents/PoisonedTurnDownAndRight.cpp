// Poisoned Turn Down And Right

#include "TurnDownAndRight.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "Settings.h"

const PoisonedTurnDownAndRight MoveFSM::StatePoisonedTurnDownAndRight;

PoisonedTurnDownAndRight::PoisonedTurnDownAndRight()
	:frameCount(8)
{
	ConsoleMsg::WriteLine("Initializing PoisonedTurnDownAndRight state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(0.0f, 2.0f, -180.0f / 8.0f));
}

void PoisonedTurnDownAndRight::Show() const
{
	ConsoleMsg::WriteLine("PoisonedTurnDownAndRight");
}

const MoveState* PoisonedTurnDownAndRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();

	/* --- Reaches the bottom of the player area --- */
	if (row == Settings::BROWBORDER)
		pNextState = &MoveFSM::StateMoveRightAndUp;
	else
		pNextState = &MoveFSM::StatePoisonedTurnDownAndLeft;

	return pNextState;
}
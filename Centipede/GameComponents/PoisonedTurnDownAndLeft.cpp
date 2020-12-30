// Poisoned Turn Down And Left

#include "PoisonedTurnDownAndLeft.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "Settings.h"

const PoisonedTurnDownAndLeft MoveFSM::StatePoisonedTurnDownAndLeft;

PoisonedTurnDownAndLeft::PoisonedTurnDownAndLeft()
	:frameCount(8)
{
	ConsoleMsg::WriteLine("Initializing PoisonedTurnDownAndLeft state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(0.0f, 2.0f, 180.0f / 8.0f));
}

void PoisonedTurnDownAndLeft::Show() const
{
	ConsoleMsg::WriteLine("PoisonedTurnDownAndLeft");
}

const MoveState* PoisonedTurnDownAndLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();

	/* --- Reaches the bottom of the player area --- */
	if (row == Settings::BROWBORDER)
		pNextState = &MoveFSM::StateMoveLeftAndUp;
	else
		pNextState = &MoveFSM::StatePoisonedTurnDownAndRight;

	return pNextState;
}


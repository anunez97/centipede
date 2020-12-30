// Move Left And Up

#include "MoveLeftAndUp.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "MushroomField.h"
#include "Settings.h"

const MoveLeftAndUp MoveFSM::StateMoveLeftAndUp;

MoveLeftAndUp::MoveLeftAndUp()
	:frameCount(8)
{
	ConsoleMsg::WriteLine("Initializing MoveLeftAndUp state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(-2.0f, 0.0f, 0.0f));
}

void MoveLeftAndUp::Show() const
{
	ConsoleMsg::WriteLine("MoveLeftAndUp");
}

const MoveState* MoveLeftAndUp::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() - 1;

	/* --- Get State of Cell; Empty, Blocked, or Poison --- */
	MushroomField::CELL_STATE state = chead->getField()->GetCellState(col, row);

	if (state == MushroomField::CELL_STATE::EMPTY)
		pNextState = &MoveFSM::StateMoveLeftAndUp;
	else if (state == MushroomField::CELL_STATE::BLOCKED || state == MushroomField::CELL_STATE::OFF_GRID)
	{
		/* --- Is in the first row of the player area --- */
		if (row == Settings::TROWBORDER)
			pNextState = &MoveFSM::StateTurnDownAndRight;
		else
			pNextState = &MoveFSM::StateTurnUpAndRight;
	}
	else // Poison
	{
		// Shouldn't happen when going up but just in case
		pNextState = &MoveFSM::StatePoisonedTurnDownAndRight;
	}

	return pNextState;
}
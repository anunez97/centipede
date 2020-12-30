// Move Right And Up

#include "MoveRightAndUp.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "MushroomField.h"
#include "Settings.h"

const MoveRightAndUp MoveFSM::StateMoveRightAndUp;

MoveRightAndUp::MoveRightAndUp()
	:frameCount(8)
{
	ConsoleMsg::WriteLine("Initializing MoveRightAndUp state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(2.0f, 0.0f, 0.0f));
}

void MoveRightAndUp::Show() const
{
	ConsoleMsg::WriteLine("MoveRightAndUp");
}

const MoveState* MoveRightAndUp::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() + 1;

	/* --- Get State of Cell; Empty, Blocked, or Poison --- */
	MushroomField::CELL_STATE state = chead->getField()->GetCellState(col, row);

	if (state == MushroomField::CELL_STATE::EMPTY)
		pNextState = &MoveFSM::StateMoveRightAndUp;
	else if (state == MushroomField::CELL_STATE::BLOCKED || state == MushroomField::CELL_STATE::OFF_GRID)
	{
		/* --- Is in the first row of the player area --- */
		if (row == Settings::TROWBORDER)
			pNextState = &MoveFSM::StateTurnDownAndLeft;
		else
			pNextState = &MoveFSM::StateTurnUpAndLeft;
	}
	else // Poison
	{
		// Shouldn't happen but just in case
		pNextState = &MoveFSM::StatePoisonedTurnDownAndLeft;
	}

	return pNextState;
}
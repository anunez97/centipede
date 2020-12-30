// Move Right And Down

#include "MoveRightAndDown.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "MushroomField.h"
#include "Settings.h"

const MoveRightAndDown MoveFSM::StateMoveRightAndDown;

MoveRightAndDown::MoveRightAndDown()
	:frameCount(8)
{
	ConsoleMsg::WriteLine("Initializing MoveRightAndDown state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(2.0f, 0.0f, 0.0f));
}

void MoveRightAndDown::Show() const
{
	ConsoleMsg::WriteLine("MoveRightAndDown");
}

const MoveState* MoveRightAndDown::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() + 1;

	/* --- Get State of Cell; Empty, Blocked, or Poison --- */
	MushroomField::CELL_STATE state = chead->getField()->GetCellState(col, row);

	if (state == MushroomField::CELL_STATE::EMPTY)
		pNextState = &MoveFSM::StateMoveRightAndDown;
	else if (state == MushroomField::CELL_STATE::BLOCKED || state == MushroomField::CELL_STATE::OFF_GRID)
	{
		/* --- Is in the last row of the player area --- */
		if (row == Settings::BROWBORDER)
			pNextState = &MoveFSM::StateTurnUpAndLeft;
		else
			pNextState = &MoveFSM::StateTurnDownAndLeft;
	}
	else // Poison
	{
		pNextState = &MoveFSM::StatePoisonedTurnDownAndLeft;
	}

	return pNextState;
}
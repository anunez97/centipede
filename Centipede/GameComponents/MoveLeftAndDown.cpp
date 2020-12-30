// Move Left And Down

#include "MoveLeftAndDown.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "MushroomField.h"
#include "Settings.h"
#include "OffsetCollection.h"

const MoveLeftAndDown MoveFSM::StateMoveLeftAndDown;

MoveLeftAndDown::MoveLeftAndDown()
	:frameCount(8)
{
	//ConsoleMsg::WriteLine("Initializing MoveLeftAndDown state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(-2.0f, 0.0f, 0.0f));
}

void MoveLeftAndDown::Show() const
{
	ConsoleMsg::WriteLine("MoveLeftAndDown");
}

const MoveState* MoveLeftAndDown::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() - 1;

	/* --- Get State of Cell; Empty, Blocked, or Poison --- */
	MushroomField::CELL_STATE state = chead->getField()->GetCellState(col, row);

	if (state == MushroomField::CELL_STATE::EMPTY)
		pNextState = &MoveFSM::StateMoveLeftAndDown;
	else if (state == MushroomField::CELL_STATE::BLOCKED || state == MushroomField::CELL_STATE::OFF_GRID)
	{
		/* --- Is in the last row of the player area --- */
		if (row == Settings::BROWBORDER)
			pNextState = &MoveFSM::StateTurnUpAndRight;
		else
			pNextState = &MoveFSM::StateTurnDownAndRight;
	}
	else // Poison
	{
		pNextState = &MoveFSM::StatePoisonedTurnDownAndRight;
	}

	return pNextState;
}
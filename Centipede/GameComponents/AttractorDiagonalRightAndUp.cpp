// Attractor Diagonal Right And Up

#include "AttractorDiagonalRightAndUp.h"

#include "AttractorFSM.h"
#include "Blaster.h"
#include "Grid.h"
#include "Settings.h"

const AttractorDiagonalRightAndUp AttractorFSM::StateDiagonalRightAndUp;

AttractorDiagonalRightAndUp::AttractorDiagonalRightAndUp()
{
	ConsoleMsg::WriteLine("Initializing DiagonalRightAndUp state");

	for (int i = 0; i < frameCounter; i++)
		MoveOffset.push_back(sf::Vector2f(2.0f, -2.0f));
}

void AttractorDiagonalRightAndUp::Show() const
{
	ConsoleMsg::WriteLine("DiagonalRightAndUp");
}

const AttractorMoveState* AttractorDiagonalRightAndUp::GetNextState(Blaster* b) const
{
	const AttractorMoveState* pNextState;

	int x = Grid::pixelstoGrid(b->GetPos().x);
	int y = Grid::pixelstoGrid(b->GetPos().y);

	if (x == Settings::RCOLBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalLeftAndUp;
	}
	else if (y == Settings::TROWBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalRightAndDown;
	}
	else
		pNextState = &AttractorFSM::StateDiagonalRightAndUp;

	return pNextState;
}
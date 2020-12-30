// Attractor Diagonal Left And Up

#include "AttractorDiagonalLeftAndUp.h"

#include "AttractorFSM.h"
#include "Blaster.h"
#include "Settings.h"
#include "Grid.h"

const AttractorDiagonalLeftAndUp AttractorFSM::StateDiagonalLeftAndUp;

AttractorDiagonalLeftAndUp::AttractorDiagonalLeftAndUp()
{
	ConsoleMsg::WriteLine("Initializing DiagonalLeftAndUp state");

	for (int i = 0; i < frameCounter; i++)
		MoveOffset.push_back(sf::Vector2f(-2.0f, -2.0f));
}

void AttractorDiagonalLeftAndUp::Show() const
{
	ConsoleMsg::WriteLine("DiagonalLeftAndUp");
}

const AttractorMoveState* AttractorDiagonalLeftAndUp::GetNextState(Blaster* b) const
{
	const AttractorMoveState* pNextState;

	int x = Grid::pixelstoGrid(b->GetPos().x);
	int y = Grid::pixelstoGrid(b->GetPos().y);

	if (x == Settings::LCOLBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalRightAndUp;
	}
	else if (y == Settings::TROWBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalLeftAndDown;
	}
	else
		pNextState = &AttractorFSM::StateDiagonalLeftAndUp;

	return pNextState;
}
// Attractor Diagonal Right And Down

#include "AttractorDiagonalRightAndDown.h"

#include "AttractorFSM.h"
#include "Blaster.h"
#include "Grid.h"
#include "Settings.h"

const AttractorDiagonalRightAndDown AttractorFSM::StateDiagonalRightAndDown;

AttractorDiagonalRightAndDown::AttractorDiagonalRightAndDown()
{
	ConsoleMsg::WriteLine("Initializing DiagonalRightAndDown state");

	for (int i = 0; i < frameCounter; i++)
		MoveOffset.push_back(sf::Vector2f(2.0f, 2.0f));
}

void AttractorDiagonalRightAndDown::Show() const
{
	ConsoleMsg::WriteLine("DiagonalRightAndDown");
}

const AttractorMoveState* AttractorDiagonalRightAndDown::GetNextState(Blaster* b) const
{
	const AttractorMoveState* pNextState;

	int x = Grid::pixelstoGrid(b->GetPos().x);
	int y = Grid::pixelstoGrid(b->GetPos().y);

	if (x == Settings::RCOLBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalLeftAndDown;
	}
	else if (y == Settings::BROWBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalRightAndUp;
	}
	else
		pNextState = &AttractorFSM::StateDiagonalRightAndDown;

	return pNextState;
}
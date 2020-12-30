// Attractor Diagonal Left And Down

#include "AttractorDiagonalLeftAndDown.h"

#include "AttractorFSM.h"
#include "Blaster.h"
#include "Settings.h"
#include "Grid.h"

const AttractorDiagonalLeftAndDown AttractorFSM::StateDiagonalLeftAndDown;

AttractorDiagonalLeftAndDown::AttractorDiagonalLeftAndDown()
{
	ConsoleMsg::WriteLine("Initializing DiagonalLeftAndDown state");

	for (int i = 0; i < frameCounter; i++)
		MoveOffset.push_back(sf::Vector2f(-2.0f, 2.0f));
}

void AttractorDiagonalLeftAndDown::Show() const
{
	ConsoleMsg::WriteLine("DiagonalLeftAndDown");
}

const AttractorMoveState* AttractorDiagonalLeftAndDown::GetNextState(Blaster* b) const
{
	const AttractorMoveState* pNextState;

	int x = Grid::pixelstoGrid(b->GetPos().x);
	int y = Grid::pixelstoGrid(b->GetPos().y);

	if (x == Settings::LCOLBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalRightAndDown;
	}
	else if (y == Settings::BROWBORDER)
	{
		pNextState = &AttractorFSM::StateDiagonalLeftAndUp;
	}
	else
		pNextState = &AttractorFSM::StateDiagonalLeftAndDown;

	return pNextState;
}
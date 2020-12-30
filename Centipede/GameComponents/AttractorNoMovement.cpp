// Attractor No Movement

#include "AttractorNoMovement.h"

#include "AttractorFSM.h"
#include "Blaster.h"
#include "Settings.h"
#include "Grid.h"

const AttractorNoMovement AttractorFSM::StateNoMovement;

AttractorNoMovement::AttractorNoMovement()
{
	ConsoleMsg::WriteLine("Initializing No Movement state");

	for (int i = 0; i < frameCounter; i++)
		MoveOffset.push_back(sf::Vector2f(0.0f, 0.0f));
}

void AttractorNoMovement::Show() const
{
	ConsoleMsg::WriteLine("NoMovement");
}

const AttractorMoveState* AttractorNoMovement::GetNextState(Blaster* b) const
{
	return &AttractorFSM::StateNoMovement;
}
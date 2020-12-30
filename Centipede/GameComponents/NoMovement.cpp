// No Movement

#include "NoMovement.h"

#include "MoveFSM.h"
#include "CentipedeHead.h"

const NoMovement MoveFSM::StateNoMovement;

NoMovement::NoMovement()
	:frameCount(8)
{
	ConsoleMsg::WriteLine("Initializing NoMovement state");

	for (int i = 0; i < frameCount; i++)
		MoveOffset.push_back(sf::Vector3f(0.0f, 0.0f, 0.0f));
}

void NoMovement::Show() const
{
	ConsoleMsg::WriteLine("NoMovement");
}

const MoveState* NoMovement::GetNextState(CentipedeHead* chead) const
{
	return &MoveFSM::StateNoMovement;
}
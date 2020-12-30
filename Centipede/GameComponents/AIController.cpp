// AI Controller

#include "AIController.h"
#include "AttractorFSM.h"
#include "Blaster.h"
#include "Settings.h"
#include "Grid.h"

AIController::AIController()
	:pBlaster(0), pMoveState(0), index(0), isEnabled(false)
{
	pMoveState = &AttractorFSM::StateDiagonalLeftAndDown;
}

AIController::~AIController()
{
}

void AIController::SetBlaster(Blaster* b)
{
	pBlaster = b;
}

void AIController::Disable()
{
	isEnabled = false;
}

void AIController::Enable()
{
	isEnabled = true;
	pMoveState = &AttractorFSM::StateDiagonalLeftAndDown;
}

void AIController::Update()
{
	if (!isEnabled)
		return;

	if (index == pMoveState->GetMoveOffset().size())
	{
		index = 0;
		pMoveState = pMoveState->GetNextState(pBlaster);
	}
	pBlaster->fire();
	pBlaster->move(pMoveState->GetMoveOffset()[index]);

	index++;
}

void AIController::Destroy()
{

}

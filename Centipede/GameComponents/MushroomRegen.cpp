// Mushroom Regeneration

#include "MushroomRegen.h"
#include "MushroomField.h"
#include "ScoreManager.h"
#include "Settings.h"
#include "CmdScore.h"
#include "Grid.h"

// Temp
#include "PlayerManager.h"

MushroomRegen* MushroomRegen::ptrInstance = nullptr;

MushroomRegen::MushroomRegen()
{
	pRegen = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomRegen);
}

MushroomRegen::~MushroomRegen()
{

}

void MushroomRegen::privRegenMushrooms(MushroomField* mf)
{
	// For every 2 Mushrooms regenerated, player gets 5 points
	int counter = 0;
	for (int i = Settings::MUSHROOM_BROW - 1; i >= Settings::MUSHROOM_TROW; i--)
	{
		for (int j = 0; j < Settings::NUM_COLS; j++)
		{
			if (mf->hasMushroom(j, i))
			{
				mf->GetGrid()->UpdateCellState(j, i, Grid::CellState::BLOCKED);
				counter += mf->GetMushroom(j, i)->Regen();
			}

			if (counter == 2)
			{
				counter = 0;

				PlayerManager::AddScore(5);
	
			}
		}
	}
}

void MushroomRegen::privTerminate()
{
	delete pRegen;
	delete ptrInstance;
	ptrInstance = nullptr;
}
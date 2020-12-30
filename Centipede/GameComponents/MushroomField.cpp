// Mushroom Field

#include "MushroomField.h"
#include "Settings.h"
#include "Grid.h"
#include "MushroomFactory.h"
#include "FleaManager.h"

MushroomField::MushroomField()
	:mushroomCnt(0), pGrid(0)
{
	mfield = new Mushroom ** [Settings::NUM_COLS];
	for (int i = 0; i < Settings::NUM_COLS; i++)
		mfield[i] = new Mushroom*[Settings::NUM_ROWS];

	for (int i = 0; i < Settings::NUM_COLS; i++) {
		for (int j = 0; j < Settings::NUM_ROWS; j++) {
			mfield[i][j] = 0;
		}
	}
}

MushroomField::~MushroomField()
{
	for (int i = 0; i < Settings::NUM_COLS; i++) 
	{
		delete[] mfield[i];
	}
	delete this->mfield;
}

void MushroomField::Initialize()
{
	size_t count = shroomPositions.size();
	GridPos pos;
	for (size_t i = 0; i < count; i++)
	{
		pos = shroomPositions.back();
		PlaceMushroom(pos.col, pos.row);
		shroomPositions.pop_back();
	}
}

void MushroomField::Deinitialize()
{
	GridPos pos;
	for (int i = 0; i < Settings::NUM_COLS; i++) {
		for (int j = 0; j < Settings::NUM_ROWS; j++) {
			if (hasMushroom(i, j))
			{
				pos.col = i;
				pos.row = j;
				shroomPositions.push_back(pos);
				mfield[i][j]->MarkForDestroy();
				mfield[i][j] = 0;
				pGrid->UpdateCellState(i, j, Grid::CellState::FREE);
			}
		}
	}
}

void MushroomField::generateField()
{
	GridPos pos;
	for (int i = Settings::MUSHROOM_TNATROW; i < Settings::MUSHROOM_BROW; i++) {
		for (int j = 0; j < 2; j++) {
			int c = rand() % Settings::NUM_COLS;

			pos.col = c;
			pos.row = i;
			shroomPositions.push_back(pos);
		}
	}

}

void MushroomField::PlaceMushroom(int c, int r)
{
	/* --- No two mushrooms in same cell --- */
	if (mfield[c][r] == 0)
	{
		if (pGrid->GetCellState(c, r) == (int)Grid::CellState::FREE)
		{

			Mushroom* m = MushroomFactory::CreateMushroom(sf::Vector2f(Grid::gridtoPixels(c), Grid::gridtoPixels(r)), c, r, this);

			mfield[c][r] = m;

			m->Initialize();

			pGrid->UpdateCellState(c, r, Grid::CellState::BLOCKED);

			/* --- Check if mushroom is in player area --- */
			if (m->getRow() >= Settings::MUSHROOM_BROW - static_cast<int>(Settings::PLAYER_ZONE_SIZE))
				mushroomCnt++;
		}
	}
}

void MushroomField::PoisonMushroom(int col, int row)
{
	if (hasMushroom(col, row))
	{
		mfield[col][row]->Poisoned();
	}
}

void MushroomField::mushroomDestroyed(Mushroom* m)
{
	mfield[m->getCol()][m->getRow()] = 0;
	
	pGrid->UpdateCellState(m->getCol(), m->getRow(), Grid::CellState::FREE);

	if (m->getRow() >= Settings::MUSHROOM_BROW - static_cast<int>(Settings::PLAYER_ZONE_SIZE) )
	{
		mushroomCnt--;

		FleaManager::SpawnFlea(mushroomCnt, this);
	}
	//hasMushroom(m->getCol(), m->getRow());
}

bool MushroomField::hasMushroom(int c, int r)
{
	if (c < 0 || c >= Settings::NUM_COLS) return false;

	if (mfield[c][r] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MushroomField::hasPoisonMushroom(int c, int r)
{
	if (!hasMushroom(c, r))
		return false;
	else
	{
		if (mfield[c][r]->getState() == Mushroom::MushroomState::POISON)
			return true;
		else
			return false;
	}
}

MushroomField::CELL_STATE MushroomField::GetCellState(int c, int r)
{
	if (c == -1 || c == Settings::NUM_COLS)
		return MushroomField::CELL_STATE::OFF_GRID;

	if (pGrid->GetCellState(c, r) == (int)Grid::CellState::FREE)
		return MushroomField::CELL_STATE::EMPTY;
	else
	{
		if (pGrid->GetCellState(c, r) == (int)Grid::CellState::BLOCKED)
			return MushroomField::CELL_STATE::BLOCKED;
		else
			return MushroomField::CELL_STATE::POISON;
	}
}

int MushroomField::GetMushroomCount()
{
	return mushroomCnt;
}

Mushroom* MushroomField::GetMushroom(int col, int row)
{
	return mfield[col][row];
}

Grid* MushroomField::GetGrid()
{
	return pGrid;
}

void MushroomField::SetGrid(Grid* grid)
{
	pGrid = grid;
	generateField();
}

void MushroomField::Terminate()
{
	for (int i = 0; i < Settings::NUM_COLS; i++) {
		delete[] mfield[i];
	}
	delete this->mfield;
}
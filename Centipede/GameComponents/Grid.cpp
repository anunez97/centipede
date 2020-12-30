// Grid

#include "Grid.h"
#include "Settings.h"

Grid::Grid()
{
	grid = new int*[Settings::NUM_COLS];

	for (int i = 0; i < Settings::NUM_COLS; i++)
	{
		grid[i] = new int[Settings::NUM_ROWS];
		for (int j = 0; j < Settings::NUM_ROWS; j++)
		{
			grid[i][j] = static_cast<int>(CellState::FREE);
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < Settings::NUM_COLS; i++)
	{
		delete[] grid[i];
	}
	delete this->grid;
}

void Grid::UpdateCellState(int col, int row, CellState state)
{
	grid[col][row] = static_cast<int>(state);
}

int Grid::GetCellState(int col, int row)
{
	return grid[col][row];
}

int Grid::pixelstoGrid(float pixels)
{
	return static_cast<int>((pixels - fmod(pixels, Settings::CELL_SIZE)) / Settings::CELL_SIZE);
}

float Grid::gridtoPixels(int grid)
{
	return (static_cast<float>(grid) * Settings::CELL_SIZE) + (Settings::CELL_SIZE / 2.0f);
}
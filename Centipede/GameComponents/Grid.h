// Grid

#ifndef _Grid
#define _Grid

#include "TEAL/CommonElements.h"

class Grid
{
public:
	Grid();
	Grid(Grid& other) = delete;
	Grid& operator=(Grid& other) = delete;
	~Grid();

	enum class CellState
	{
		BLOCKED,
		POISON,
		FREE
	};

	static int pixelstoGrid(float);
	static float gridtoPixels(int);

	void UpdateCellState(int col, int row, CellState state);
	int GetCellState(int col, int row);

private:
	int** grid;
};

#endif _Grid
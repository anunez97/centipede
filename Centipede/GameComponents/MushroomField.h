// Mushroom Field

#ifndef _MushroomField
#define _MushroomField

#include "TEAL/CommonElements.h"
#include "Mushroom.h"
#include "CritterManager.h"

class Mushroom;
class Grid;

class MushroomField
{
public:
	MushroomField();
	MushroomField(const MushroomField&) = delete;
	MushroomField& operator=(const MushroomField&) = delete;
	~MushroomField();

	enum CELL_STATE
	{
		EMPTY,
		BLOCKED,
		POISON,
		OFF_GRID
	};

	struct GridPos
	{
		int col;
		int row;
	};

	void Initialize();
	void Deinitialize();
	void generateField();
	void PlaceMushroom(int r, int c);
	void PoisonMushroom(int col, int row);
	void mushroomDestroyed(Mushroom *m);
	bool hasMushroom(int col, int row);
	bool hasPoisonMushroom(int col, int row);
	CELL_STATE GetCellState(int col, int row);
	int GetMushroomCount();
	Mushroom* GetMushroom(int col, int row);
	Grid* GetGrid();
	void SetGrid(Grid* grid);

	void Terminate();

private:
	std::vector<GridPos> shroomPositions;
	Mushroom*** mfield;
	Grid* pGrid;
	int mushroomCnt;

};

#endif _MushroomField
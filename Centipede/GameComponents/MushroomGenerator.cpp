/*// Mushroom Generator

#include "MushroomGenerator.h"
#include "Settings.h"
//#define ROW_NUM 30
//#define COL_NUM 30
//#define TBORDER 3 // highest row a mushroom can spawn naturally
//#define BBORDER 30 // lowest row

MushroomGenerator::MushroomGenerator(MushroomField* mf)
	:mfield(mf)
{
	generateField();
}

void MushroomGenerator::generateField()
{

	for (int i = Settings::MUSHROOM_TROW; i < Settings::MUSHROOM_BROW; i++) {
		for (int j = 0; j < 2; j++) {
			//this->mfield->PlaceMushroom(new Mushroom(this->mfield), i, rand() % Settings::NUM_COLS);
		}
	}
	//mfield->PlaceMushroom(new Mushroom(this->mfield), 30, 0);
	//mfield->PlaceMushroom(new Mushroom(this->mfield), 31, 0);
}

void MushroomGenerator::setField(MushroomField* mf) 
{
	this->mfield = mf;
	generateField();
}

void MushroomGenerator::terminateField()
{
	delete mfield;
}*/
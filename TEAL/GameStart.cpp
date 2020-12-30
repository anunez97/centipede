// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"
#include "CommonElements.h"
#include "..//Settings.h"

void Game::GameStart()
{
	WindowManager::SetWindowSize(static_cast<int>(Settings::CELL_SIZE) * Settings::NUM_COLS, 
		static_cast<int>(Settings::CELL_SIZE) * Settings::NUM_ROWS);
}
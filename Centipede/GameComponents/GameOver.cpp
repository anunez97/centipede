// High Score

#include "GameOver.h"
#include "Grid.h"
#include "PlayerManager.h"

GameOver::GameOver()
	:textStartRow(16), textStartCol(11)
{
	text = "GAME OVER";
	nextPos.x = Grid::gridtoPixels(textStartCol);
	nextPos.y = Grid::gridtoPixels(textStartRow);
}

GameOver::~GameOver()
{

}

void GameOver::Display()
{
	nextPos.x = Grid::gridtoPixels(textStartCol);
	for (size_t i = 0; i < text.length(); i++)
	{
		PlayerManager::GetCurrentGrid()->UpdateCellState(Grid::pixelstoGrid(nextPos.x),
			Grid::pixelstoGrid(nextPos.y), Grid::CellState::BLOCKED);
		textlist.push_back(TextFont.GetGlyph(text.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}

	SetAlarm(0, 5.0f);
}

void GameOver::Reset()
{
	size_t size = textlist.size();
	for (size_t i = 0; i < size; i++)
	{
		textlist.front()->MarkForDestroy();
		textlist.pop_front();
	}
}

void GameOver::Alarm0()
{
	Reset();
}

void GameOver::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = textlist.begin(); it != textlist.end(); it++)
		(*it)->Draw();
}
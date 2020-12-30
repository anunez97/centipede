// Player 2 Lives

#include "Player2Lives.h"
#include "Grid.h"
#include "Settings.h"

Player2Lives::Player2Lives()
	:livesLength(4), livesStart(24)
{
	p2lives = "!!!";
	nextPos.x = Grid::gridtoPixels(livesStart);
	nextPos.y = Grid::gridtoPixels(0);
}

Player2Lives::~Player2Lives()
{

}

void Player2Lives::Display()
{
	nextPos.x = Grid::gridtoPixels(livesStart);

	for (size_t i = 0; i < p2lives.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(p2lives.at(i), nextPos));
		nextPos.x -= TextFont.CellWidth();
	}
}

void Player2Lives::UpdateLives(int lives)
{
	Reset();

	nextPos.x = Grid::gridtoPixels(livesStart);
	for (int i = 0; i < livesLength; i++)
	{
		if (lives != 0)
		{
			textlist.push_back(TextFont.GetGlyph('!', nextPos));
			nextPos.x -= TextFont.CellWidth();
			lives--;
		}
		else
		{
			textlist.push_back(TextFont.GetGlyph(' ', nextPos));
			nextPos.x -= TextFont.CellWidth();
		}
	}
}

void Player2Lives::Reset()
{
	size_t size = textlist.size();
	for (size_t i = 0; i < size; i++)
	{
		textlist.front()->MarkForDestroy();
		textlist.pop_front();
	}
}

void Player2Lives::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = textlist.begin(); it != textlist.end(); it++)
		(*it)->Draw();
}
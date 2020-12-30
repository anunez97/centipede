// Player 1 Lives

#include "Player1Lives.h"
#include "Grid.h"

Player1Lives::Player1Lives()
	:livesLength(4), livesStart(6)
{
	p1lives = "!!!";
	nextPos.x = Grid::gridtoPixels(livesStart);
	nextPos.y = Grid::gridtoPixels(0);
}

Player1Lives::~Player1Lives()
{

}

void Player1Lives::Display()
{
	nextPos.x = Grid::gridtoPixels(livesStart);

	for (size_t i = 0; i < p1lives.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(p1lives.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}
}

void Player1Lives::UpdateLives(int lives)
{
	Reset();

	nextPos.x = Grid::gridtoPixels(livesStart);
	for (int i = 0; i < livesLength; i++)
	{
		if (lives != 0)
		{
			textlist.push_back(TextFont.GetGlyph('!', nextPos));
			nextPos.x += TextFont.CellWidth();
			lives--;
		}
		else
		{
			textlist.push_back(TextFont.GetGlyph(' ', nextPos));
			nextPos.x += TextFont.CellWidth();
		}
	}
}

void Player1Lives::Reset()
{
	size_t size = textlist.size();
	for (size_t i = 0; i < size; i++)
	{
		textlist.front()->MarkForDestroy();
		textlist.pop_front();
	}
}

void Player1Lives::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = textlist.begin(); it != textlist.end(); it++)
		(*it)->Draw();
}
// Player 1 Score

#include "Player1Score.h"
#include "Grid.h"

Player1Score::Player1Score()
	:scoreLength(6)
{
	p1score = "    00";
	nextPos.x = Grid::gridtoPixels(0);
	nextPos.y = Grid::gridtoPixels(0);
}

Player1Score::~Player1Score()
{

}

void Player1Score::Display()
{
	nextPos.x = Grid::gridtoPixels(0);
	nextPos.y = Grid::gridtoPixels(0);
	// Player 1 Score
	for (size_t i = 0; i < p1score.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(p1score.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}
}

void Player1Score::UpdateScore(int score)
{
	std::string tmp = std::to_string(score);

	if (tmp.length() == 1)
		tmp = "0" + tmp;

	Reset();

	nextPos.x = Grid::gridtoPixels(scoreLength - tmp.length());
	for (size_t i = 0; i < tmp.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(tmp.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}
}

void Player1Score::Reset()
{
	size_t size = textlist.size();
	for (size_t i = 0; i < size; i++)
	{
		textlist.back()->MarkForDestroy();
		textlist.pop_back();
	}
}

void Player1Score::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = textlist.begin(); it != textlist.end(); it++)
		(*it)->Draw();
}
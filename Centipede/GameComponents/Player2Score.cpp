// Player 2 Score

#include "Player2Score.h"
#include "Grid.h"
#include "Settings.h"

Player2Score::Player2Score()
	:scoreLength(6)
{
	p2score = "    00";
	nextPos.x = Grid::gridtoPixels(0);
	nextPos.y = Grid::gridtoPixels(0);
}

Player2Score::~Player2Score()
{

}

void Player2Score::Display()
{
	nextPos.x = Grid::gridtoPixels(Settings::NUM_COLS - p2score.length());

	for (size_t i = 0; i < p2score.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(p2score.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}
}

void Player2Score::UpdateScore(int score)
{
	std::string tmp = std::to_string(score);

	if (tmp.length() == 1)
		tmp = "0" + tmp;

	Reset();

	nextPos.x = Grid::gridtoPixels(Settings::NUM_COLS - tmp.length());
	for (size_t i = 0; i < tmp.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(tmp.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}
}

void Player2Score::Reset()
{
	size_t size = textlist.size();
	for (size_t i = 0; i < size; i++)
	{
		textlist.back()->MarkForDestroy();
		textlist.pop_back();
	}
}

void Player2Score::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = textlist.begin(); it != textlist.end(); it++)
		(*it)->Draw();
}
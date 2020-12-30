// High Score

#include "HighScore.h"
#include "Grid.h"

HighScore::HighScore()
	:scoreLength(4), scoreStart(13), currHighScore(0)
{
	highscore = "00";
	nextPos.x = Grid::gridtoPixels(scoreStart);
	nextPos.y = Grid::gridtoPixels(0);
}

HighScore::~HighScore()
{

}

void HighScore::Display(int score)
{
	currHighScore = score;
	highscore = std::to_string(score);
	nextPos.x = Grid::gridtoPixels(scoreStart);

	for (size_t i = 0; i < highscore.length(); i++)
	{
		textlist.push_back(TextFont.GetGlyph(highscore.at(i), nextPos));
		nextPos.x += TextFont.CellWidth();
	}
}

void HighScore::UpdateScore(int score)
{
	if (score > currHighScore)
	{
		Reset();

		currHighScore = score;

		std::string s = std::to_string(score);

		if (s.length() == 1)
			s = "0" + s;

		nextPos.x = Grid::gridtoPixels(scoreStart);

		for (size_t i = 0; i < s.length(); i++)
		{
			textlist.push_front(TextFont.GetGlyph(s.at(i), nextPos));
			nextPos.x += TextFont.CellWidth();
		}
	}
}

void HighScore::Reset()
{
	size_t size = textlist.size();
	for (size_t i = 0; i < size; i++)
	{
		textlist.front()->MarkForDestroy();
		textlist.pop_front();
	}
}

void HighScore::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = textlist.begin(); it != textlist.end(); it++)
		(*it)->Draw();
}
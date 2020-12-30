// HighScore

#ifndef _HighScore
#define _HighScore

#include "TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class HighScore : public GameObject
{
public:
	HighScore();
	HighScore(HighScore& other) = delete;
	HighScore& operator=(HighScore& other) = delete;
	~HighScore();

	virtual void Draw();

	void Display(int score);
	void UpdateScore(int lives);
	void Reset();

private:
	std::list<Glyph*> textlist;
	Font TextFont;
	sf::Vector2f nextPos;
	std::string highscore;
	int scoreLength;
	int scoreStart;
	int currHighScore;

};

#endif _Player1Lives
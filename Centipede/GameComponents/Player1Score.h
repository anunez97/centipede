// Player 1 Score

#ifndef _Player1Score
#define _Player1Score

#include "TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class Player1Score : public GameObject
{
public:
	Player1Score();
	Player1Score(Player1Score& other) = delete;
	Player1Score& operator=(Player1Score& other) = delete;
	~Player1Score();

	virtual void Draw();

	void Display();
	void UpdateScore(int score);
	void Reset();

private:
	std::list<Glyph*> textlist;
	Font TextFont;
	sf::Vector2f nextPos;
	std::string p1score;
	int scoreLength;
};

#endif _Player1Score
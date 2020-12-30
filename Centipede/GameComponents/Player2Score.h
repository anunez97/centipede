// Player 2 Score

#ifndef _Player2Score
#define _Player2Score

#include "TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class Player2Score : public GameObject
{
public:
	Player2Score();
	Player2Score(Player2Score& other) = delete;
	Player2Score& operator=(Player2Score& other) = delete;
	~Player2Score();

	virtual void Draw();

	void Display();
	void UpdateScore(int score);
	void Reset();

private:
	std::list<Glyph*> textlist;
	Font TextFont;
	sf::Vector2f nextPos;
	std::string p2score;
	int scoreLength;
};

#endif _Player2Score
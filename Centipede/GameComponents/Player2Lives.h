// Player 2 Lives

#ifndef _Player2Lives
#define _Player2Lives

#include "TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class Player2Lives : public GameObject
{
public:
	Player2Lives();
	Player2Lives(Player2Lives& other) = delete;
	Player2Lives& operator=(Player2Lives& other) = delete;
	~Player2Lives();

	virtual void Draw();

	void Display();
	void UpdateLives(int lives);
	void Reset();

private:
	std::list<Glyph*> textlist;
	Font TextFont;
	sf::Vector2f nextPos;
	std::string p2lives;
	int livesLength;
	int livesStart;

};

#endif _Player2Lives
// Player 1 Lives

#ifndef _Player1Lives
#define _Player1Lives

#include "TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class Player1Lives : public GameObject
{
public:
	Player1Lives();
	Player1Lives(Player1Lives& other) = delete;
	Player1Lives& operator=(Player1Lives& other) = delete;
	~Player1Lives();

	virtual void Draw();

	void Display();
	void UpdateLives(int lives);
	void Reset();

private:
	std::list<Glyph*> textlist;
	Font TextFont;
	sf::Vector2f nextPos;
	std::string p1lives;
	int livesLength;
	int livesStart;

};

#endif _Player1Lives
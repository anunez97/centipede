// GameOver

#ifndef _GameOver
#define _GameOver

#include "TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class GameOver : public GameObject
{
public:
	GameOver();
	GameOver(GameOver& other) = delete;
	GameOver& operator=(GameOver& other) = delete;
	~GameOver();

	virtual void Draw();

	void Display();
	void Reset();
	virtual void Alarm0();

private:
	std::list<Glyph*> textlist;
	Font TextFont;
	sf::Vector2f nextPos;
	std::string text;
	int textStartRow;
	int textStartCol;

};

#endif _GameOver
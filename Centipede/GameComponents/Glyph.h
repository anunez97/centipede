// Glyph

#ifndef _Glyph
#define _Glyph

#include "TEAL/CommonElements.h"
#include "SFML/Graphics.hpp"

class Spritesheet;

class Glyph : public GameObject
{
private:
	Spritesheet* sprsheet;
	int cellIndex;
	sf::Vector2f Pos;
	CollisionTools::TextureBitmap* bitmap;
	AnimatedSprite MainSprite;

public:
	Glyph();

	void Draw();
	virtual void Destroy();

	void Initialize(Spritesheet* sheet, int cellInd, sf::Vector2f pos);
	sf::Vector2f GetPos();
};

#endif _Glyph
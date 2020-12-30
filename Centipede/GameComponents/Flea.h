// Flea

#ifndef _Flea
#define _Flea

#include "TEAL/CommonElements.h"
#include "MushroomField.h"
#include "Settings.h"

class Blaster;
class Bullet;
class CmdScore;

class Flea : public GameObject
{
public:
	Flea();
	Flea(Flea& other) = delete;
	Flea& operator=(Flea& other) = delete;
	~Flea() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject*) {};
	virtual void Collision(Blaster*);
	virtual void Collision(Bullet*);

	void Initialize(sf::Vector2f, MushroomField *, CmdScore* death);
	void move();
	void spawnMushroom();

private:
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;
	CollisionTools::TextureBitmap* bitmap;
	MushroomField* mfield;
	CmdScore* pDeath;

	float SPEED;
	float offset;

	int currRow;
	int col;
	int nextRow;

	int health;
	int maxHealth;

};

#endif _Flea
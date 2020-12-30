// Scorpion

#ifndef _Scorpion
#define _Scorpion

#include "TEAL/CommonElements.h"

class Bullet;
class CmdScore;

class Scorpion : public GameObject
{
public:
	Scorpion();
	Scorpion(Scorpion& other) = delete;
	Scorpion& operator=(Scorpion& other) = delete;
	~Scorpion() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject*) {};
	virtual void Collision(Bullet*);

	void Initialize(sf::Vector2f, CmdScore* death);
	void move();

private:
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;
	CollisionTools::TextureBitmap* bitmap;
	CmdScore* pDeath;

	float SPEED;
	float offset;
	float dir;

	int currCol;
	int nextCol;
	int row;
};

#endif _Scorpion
// Bullet

#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"
#include "Blaster.h"

class Mushroom;
class Spider;
class Scorpion;
class Flea;
class CentipedeHead;
class CentipedeBody;
class Glyph;

class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	~Bullet() = default;

	void Initialize(sf::Vector2f p, Blaster* b);
	void move();

	sf::Vector2f GetOrigPos();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Spider*);
	virtual void Collision(Scorpion*);
	virtual void Collision(Flea*);
	virtual void Collision(CentipedeHead*);
	virtual void Collision(CentipedeBody*);
	virtual void Collision(Glyph*);

private:
	float SPEED;
	int rowLimit; // Used to determine max height for bullet
	int currRow;

	Blaster* bptr;
	sf::Vector2f Pos;
	sf::Vector2f origPos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

};

#endif _Bullet
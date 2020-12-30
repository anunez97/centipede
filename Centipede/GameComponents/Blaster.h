// Blaster

#ifndef _Blaster
#define _Blaster

#include "TEAL/CommonElements.h"
#include "KeyboardController.h"

class Mushroom;
class Flea;
class Spider;
class CentipedeHead;
class Player;
class CentipedeBody;
class Bullet;

class Blaster : public GameObject
{
public:
	Blaster();
	Blaster(Blaster& other) = delete;
	Blaster& operator=(Blaster& other) = delete;
	~Blaster() = default;

	void Initialize(sf::Vector2f, Player*);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Flea* other);
	virtual void Collision(Spider* other);
	virtual void Collision(CentipedeHead* other);
	virtual void Collision(CentipedeBody* other);

	void fire();
	void reload();
	void move(sf::Vector2f);
	sf::Vector2f GetPos();

private:
	int bulletCnt;

	sf::Vector2f currPos;
	sf::Vector2f prevPos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;
	KeyboardController* kbptr;
	Player* pPlayer;
	Bullet* pBullet;
};



#endif _Blaster

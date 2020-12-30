// Mushroom

#ifndef _Mushroom
#define _Mushroom

#include "TEAL/CommonElements.h"

class MushroomField;
class Bullet;
class Scorpion;
class Spider;
class CmdScore;

class Mushroom : public GameObject
{
public:
	Mushroom();
	Mushroom(Mushroom& other) = delete;
	Mushroom& operator=(Mushroom& other) = delete;
	~Mushroom() = default;

	enum MushroomState
	{
		NORMAL,
		POISON
	};

	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* obj) {};
	virtual void Collision(Bullet* other);
	virtual void Collision(Spider* other);
	void Poisoned();
	void Initialize();

	sf::Vector2f getPos();
	MushroomState getState();

	void SetVars(sf::Vector2f pos, int col, int row, MushroomField* mf, CmdScore* normal, CmdScore* poison);

	int getRow();
	int getCol();
	int getHealth();

	int Regen();

private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;
	MushroomField* mfield;
	CmdScore* pNormalMushroomDeath;
	CmdScore* pPoisonMushroomDeath;

	sf::Vector2f Pos;
	int maxHealth;
	int health;
	int row;
	int col;

	MushroomState mState;
};

#endif _Mushroom
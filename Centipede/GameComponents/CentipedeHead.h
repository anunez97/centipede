// Centipede Head

#ifndef _CentipedeHead
#define _CentipedeHead

#include "TEAL/CommonElements.h"
#include "Centipede.h"
#include "CentipedeHeadFactory.h"

class MushroomField;
class Blaster;
class Bullet;
class MoveState;
class CmdScore;

class CentipedeHead : public Centipede
{
public:
	CentipedeHead();
	CentipedeHead(CentipedeHead& other) = delete;
	CentipedeHead& operator=(CentipedeHead& other) = delete;
	~CentipedeHead() = default;

	void Initialize(sf::Vector2f pos, MushroomField* mf, int bodyCnt, CentipedeHeadFactory::Direction dir, CmdScore* death);
	void Initialize(sf::Vector2f pos, MushroomField* mf, Centipede* next, const MoveState* state, int index, float rotation, CmdScore* death);

	void Kill();
	void StopMovement();
	int getRow();
	int getCol();
	MushroomField* getField();
	void setNext(Centipede*);
	void setPrev(Centipede*);
	Centipede* getNext();
	Centipede* getPrev();
	float getRotation();
	int getIndex();
	const MoveState* getMoveState();
	void setMoveState(const MoveState* state);
	void CreateBody(int bodyCnt);
	void Split();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject*) {};
	virtual void Collision(Blaster*);
	virtual void Collision(Bullet*);

private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;
	MushroomField* pMField;
	const MoveState* pCurrentState;
	Centipede* pNext;
	Centipede* pPrev;
	CmdScore* pDeath;
	
	sf::Vector2f Pos;
	int col;
	int row;
	int index;

};

#endif _CentipedeHead
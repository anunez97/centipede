// Centipede Body

#ifndef _CentipedeBody
#define _CentipedeBody

#include "TEAL/CommonElements.h"
#include "Centipede.h"

class MushroomField;
class Blaster;
class Bullet;
class MoveState;
class CmdScore;

class CentipedeBody : public Centipede
{
public:
	CentipedeBody();
	CentipedeBody(CentipedeBody& other) = delete;
	CentipedeBody& operator=(CentipedeBody& other) = delete;
	~CentipedeBody();

	void Initialize(sf::Vector2f pos, MushroomField* mf, Centipede* prev, CmdScore* death);
	
	void setPrev(Centipede*);
	void setNext(Centipede*);
	void setMoveState(const MoveState*);
	void setRotation(float degree);

	MushroomField* getField();
	int getRow();
	int getCol();
	sf::Vector2f getPos();
	Centipede* getNext();
	Centipede* getPrev();
	int getIndex();
	const MoveState* getMoveState();
	float getRotation();

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
	const MoveState* pNextState;
	const MoveState* pCurrentState;
	Centipede* pPrev;
	Centipede* pNext;
	CmdScore* pDeath;

	sf::Vector2f Pos;
	int col;
	int row;
	int index;
};

#endif _CentipedeBody
// Centipede

#ifndef _Centipede
#define _Centipede

#include "TEAL/CommonElements.h"

class MoveState;


class Centipede : public GameObject
{
public:
	virtual void setPrev(Centipede*) {};
	virtual void setNext(Centipede*) {};
	virtual void setRotation(float degree) {};
	virtual void setIndex(int index) {};
	virtual void setMoveState(const MoveState*) {};
	virtual float getRotation() { return 0.0f; }

	virtual Centipede* getNext() { return 0; };
	virtual Centipede* getPrev() { return 0; };
	virtual sf::Vector2f getPos() { return sf::Vector2f(0.0f, 0.0f); }
	virtual int getIndex() { return 0; }

	virtual const MoveState* getMoveState() { return 0; }
};

#endif _Centipede
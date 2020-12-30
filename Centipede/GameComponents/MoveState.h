// Move State

#ifndef _MoveState
#define _MoveState

#include "TEAL/CommonElements.h"

class CentipedeHead;

class MoveState
{
public:
	MoveState() {};
	const std::vector<sf::Vector3f> GetMoveOffsets() const { return MoveOffset; }
	virtual const MoveState* GetNextState(CentipedeHead* chead) const = 0;
	virtual void Show() const = 0;

protected:
	std::vector<sf::Vector3f> MoveOffset;
};

#endif _MoveState
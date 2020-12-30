// Attractor Move State
#ifndef _AttractorMoveState
#define _AttractorMoveState

#include "TEAL/CommonElements.h"

class Blaster;

class AttractorMoveState
{
public:
	AttractorMoveState() {};
	const std::vector<sf::Vector2f> GetMoveOffset() const { return MoveOffset; }
	virtual const AttractorMoveState* GetNextState(Blaster* b) const = 0;
	virtual void Show() const = 0;

protected:
	std::vector<sf::Vector2f> MoveOffset;
	int frameCounter = 16;

};

#endif _AttractorMoveState
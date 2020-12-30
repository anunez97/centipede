// Score By Distance (Spider)

#ifndef _CmdScoreByDistance
#define _CmdScoreByDistance

#include "CmdScore.h"
#include "TEAL/CommonElements.h"

class CmdScoreByDistance : public CmdScore
{
private:
	int distance;
	int points;

public:
	CmdScoreByDistance(int dist, int val);
	virtual void Execute() override;
};

#endif _CmdScoreByDistance
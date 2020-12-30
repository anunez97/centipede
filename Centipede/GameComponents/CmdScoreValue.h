// Score Values

#ifndef _CmdScoreValue
#define _CmdScoreValue

#include "TEAL/CommonElements.h"
#include "CmdScore.h"

class CmdScoreValue : public CmdScore
{
protected:
	int points;

public:
	CmdScoreValue() = delete;
	CmdScoreValue(int val);

	virtual void Execute() override;
};

#endif _CmdScoreValue
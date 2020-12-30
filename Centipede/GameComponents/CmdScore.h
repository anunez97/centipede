// Command Pattern for Scoring

#ifndef _CmdScore
#define _CmdScore

class CmdScore
{
public:
	CmdScore() = default;
	CmdScore(CmdScore& other) = delete;
	CmdScore& operator=(CmdScore& other) = delete;
	~CmdScore() {};

	virtual void Execute() = 0;
};

#endif _CmdScore
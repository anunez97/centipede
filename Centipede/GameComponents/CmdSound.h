// Command Pattern for Sounds

#ifndef _CmdSound
#define _CmdSound

class CmdSound
{
public:
	CmdSound() = default;
	CmdSound(CmdSound& other) = delete;
	CmdSound& operator=(CmdSound& other) = delete;
	~CmdSound() {};

	virtual void Execute() = 0;
	virtual void Stop() = 0;
};

#endif _CmdSound
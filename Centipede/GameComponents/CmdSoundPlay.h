// Sound Play

#ifndef _CmdSoundPlay
#define _CmdSoundPlay

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundPlay : public CmdSound
{
protected:
	sf::Sound sound;

public:
	CmdSoundPlay() = delete;
	CmdSoundPlay(sf::Sound snd);

	virtual void Execute() override;
	virtual void Stop() override;
};

#endif _CmdSoundPlay
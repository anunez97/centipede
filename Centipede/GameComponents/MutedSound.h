// Muted Sound

#ifndef _MutedSound
#define _MutedSound

#include "SoundBase.h"

class CmdSound;

class MutedSound : public SoundBase
{
public:
	MutedSound() {};

	MutedSound(MutedSound& other) = delete;
	MutedSound& operator=(MutedSound& other) = delete;
	~MutedSound() = default;

	void SendPlayCommand(CmdSound* cmd) {};
	void SendStopCommand(CmdSound* cmd) {};

	void PlaySounds() {};
	void StopSounds() {};
};

#endif _MutedSound
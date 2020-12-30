// Command Sound Play

#include "CmdSoundPlay.h"
#include "SoundManager.h"

CmdSoundPlay::CmdSoundPlay(sf::Sound snd)
	:sound(snd)
{
}

void CmdSoundPlay::Execute()
{
	SoundManager::PlaySnd(sound);
}

void CmdSoundPlay::Stop()
{
	SoundManager::StopSnd(sound);
}
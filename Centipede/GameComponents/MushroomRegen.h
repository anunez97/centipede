// Mushroom Regeneration

#ifndef _MushroomRegen
#define _MushroomRegen

#include <vector>

class Mushroom;
class MushroomField;
class CmdScore;

class MushroomRegen
{
private:
	static MushroomRegen* ptrInstance;

	static MushroomRegen& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new MushroomRegen;
		return *ptrInstance;
	}

	MushroomRegen();
	MushroomRegen(MushroomRegen& other) = delete;
	MushroomRegen& operator=(MushroomRegen& other) = delete;
	~MushroomRegen();

	void privRegenMushrooms(MushroomField* mf);
	void privTerminate();

	CmdScore* pRegen;

public:
	static void RegenMushrooms(MushroomField* mf) { Instance().privRegenMushrooms(mf); };
	static void Terminate() { Instance().privTerminate(); }
};

#endif _MushroomRegen
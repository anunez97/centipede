// CentipedeBody Factory

#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory

#include "TEAL/CommonElements.h"
#include "CentipedeBodyObjectPool.h"

class GameObject;
class MushroomField;
class Centipede;
class CmdScore;

class CentipedeBodyFactory
{
private:
	// Singleton
	static CentipedeBodyFactory* ptrInstance;

	CentipedeBodyFactory();
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator=(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() = default;

	static CentipedeBodyFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeBodyFactory();
		return *ptrInstance;
	}

	CentipedeBodyObjectPool CentipedeBodyPool;
	CmdScore* pDeath;

	void privCreateCentipedeBody(sf::Vector2f pos, MushroomField* mf, Centipede* prev);
	void privRecycleCentipedeBody(GameObject* b);
	void privTerminate();

public:
	static void CreateCentipedeBody(sf::Vector2f pos, MushroomField* mf, Centipede* prev) { Instance().privCreateCentipedeBody(pos, mf, prev); }
	static void RecycleCentipedeBody(GameObject* b) { Instance().privRecycleCentipedeBody(b); }

	static void Terminate() { Instance().privTerminate(); }

};

#endif _CentipedeBodyFactory
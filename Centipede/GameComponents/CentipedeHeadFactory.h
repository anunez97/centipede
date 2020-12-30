// CentipedeHead Factory

#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include "TEAL/CommonElements.h"
#include "CentipedeHeadObjectPool.h"

class GameObject;
class MushroomField;
class Centipede;
class MoveState;
class CmdScore;

class CentipedeHeadFactory
{
private:
	// Singleton
	static CentipedeHeadFactory* ptrInstance;

	CentipedeHeadFactory();
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;
	CentipedeHeadFactory& operator=(const CentipedeHeadFactory&) = delete;
	~CentipedeHeadFactory() = default;

	static CentipedeHeadFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeHeadFactory();
		return *ptrInstance;
	}

	CentipedeHeadObjectPool CentipedeHeadPool;
	CmdScore* pDeath;
	CmdScore* pLvlFinished;

	void privCreateCentipedeHead(sf::Vector2f pos, int bodyCnt, MushroomField* mf);
	void privRecycleCentipedeHead(GameObject* b);
	void privConvertCentipedeBody(sf::Vector2f pos, MushroomField* mf, Centipede* next, const MoveState* state, int index, float rotation);

public:
	static void CreateCentipedeHead(sf::Vector2f pos, int bodyCnt, MushroomField* mf) { return Instance().privCreateCentipedeHead(pos, bodyCnt, mf); }
	static void RecycleCentipedeHead(GameObject* b) { Instance().privRecycleCentipedeHead(b); }
	static void ConvertCentipedeBody(sf::Vector2f pos, MushroomField* mf, Centipede* next, const MoveState* state, int index, float rotation) 
	{ Instance().privConvertCentipedeBody(pos, mf, next, state, index, rotation); };
	static void LevelFinished();

	static void Terminate();

	enum Direction
	{
		LEFT,
		RIGHT
	};

};

#endif _CentipedeHeadFactory
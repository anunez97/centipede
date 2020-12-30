// GameController
// Andre Berthiaume, March 2013

#ifndef _GameController
#define _GameController

#include "TEAL\CommonElements.h"

class GameController 
{
public:
	static GameController* ptrInstance;									// set up as a singleton
	GameController();									// Private constructor 
	GameController( const GameController&);				// Prevent copy-construction
	GameController& operator=(const GameController&);	// Prevent assignment

	static GameController& Instance()					// Access reference (all public methods will be static)
	{
		if (! ptrInstance) 
			ptrInstance = new GameController;
		return *ptrInstance;
	};

	void ResetScore();
	void AddScore(int v);
	int GetScore();

	void PlayerDies();

	static const int GameAreaTop = 100;
	static const int GameAreaBottom = 700;
	static const int GameAreaRight = 1024;
	static const int GameAreaLeft = 50;

	static void Terminate();

private:
	int Score;
};

#endif _GameController
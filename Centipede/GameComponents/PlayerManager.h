// Player Manager

#ifndef _PlayerManager
#define _PlayerManager

#include "TEAL/CommonElements.h"

class Controller;
class AIController;
class KeyboardController;
class Blaster;
class Player;
class MushroomField;
class Grid;
class CentralManager;

class PlayerManager
{
private:
	static PlayerManager* ptrInstance;

	static PlayerManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new PlayerManager;
		return *ptrInstance;
	}

	void privSetController(Controller*);
	void privSetCentral(CentralManager* cm);
	void privSwitchPlayer();
	void privCreatePlayer();
	void privCreateAI();
	void privStartAI();
	void privResetAI();
	void privAddScore(int val);
	void privTerminate();

	MushroomField* privGetCurrentField();
	Grid* privGetCurrentGrid();
	int privGetP1Score();
	int privGetP2Score();
	int privGetCurrentWave();
	int privGetP1Lives();
	int privGetP2Lives();
	void privIncreaseCurrentWave();

	void RespawnPlayer();
	void RespawnAI();

	Controller* pController;
	AIController* pAIController;
	KeyboardController* pKeyboardController;
	Player* pCurrPlayer;
	Player* pPlayer1;
	Player* pPlayer2;
	Player* pPlayerAI;
	MushroomField* pCurrField;
	CentralManager* pCentral;
	int ScoreBonus;
	int multiplyBonus;

public:
	PlayerManager();
	PlayerManager(PlayerManager& other) = delete;
	PlayerManager& operator=(PlayerManager& other) = delete;
	~PlayerManager() = default;

	static void SetController(Controller* c) { Instance().privSetController(c); }
	static void SetCentral(CentralManager* cm) { Instance().privSetCentral(cm); }

	static void SwitchPlayer(){ Instance().privSwitchPlayer(); }
	static void CreatePlayer() { Instance().privCreatePlayer(); }
	static void CreateAI() { Instance().privCreateAI(); }
	static void StartAI() { Instance().privStartAI(); }
	static void ResetAI() { Instance().privResetAI(); }
	static void AddScore(int val) { Instance().privAddScore(val); }

	static MushroomField* GetCurrentField() { return Instance().privGetCurrentField(); }
	static Grid* GetCurrentGrid() { return Instance().privGetCurrentGrid(); }
	static int GetP1Score() { return Instance().privGetP1Score(); }
	static int GetP2Score() { return Instance().privGetP2Score(); }

	static int GetP1Lives() { return Instance().privGetP1Lives(); }
	static int GetP2Lives() { return Instance().privGetP2Lives(); }

	static int GetCurrentWave() { return Instance().privGetCurrentWave(); }
	static void IncreaseCurrentWave() { Instance().privIncreaseCurrentWave(); }

	static void Terminate() { Instance().privTerminate(); }

};

#endif _PlayerManager
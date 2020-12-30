// HUD

#ifndef _HUD
#define _HUD

class HighScoreList;
class Player1Score;
class Player1Lives;
class Player2Score;
class Player2Lives;
class HighScore;
class Text;
class GameOver;
class CentralManager;

class HUD
{
private:
	static HUD* ptrInstance;

	static HUD& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new HUD;
		return *ptrInstance;
	}

	HUD();
	HUD(HUD& other) = delete;
	HUD& operator=(HUD& other) = delete;
	~HUD() = default;

	void privInitialDisplay();
	void privOnePlayerDisplay();
	void privTwoPlayerDisplay();
	void privGameOverDisplay();
	void privSPlayerDisplay();
	void privResetDisplay();
	
	void privUpdateP1Score();
	void privUpdateP1Lives();

	void privUpdateP2Score();
	void privUpdateP2Lives();

	void privUpdateHighScore(int score);
	void privUpdateHighScoreList(int p1score, int p2score);

	void privSetCentralManager(CentralManager* cm);
	CentralManager* privGetCentralManager();

	Player1Score* player1score;
	Player1Lives* player1lives;
	Player2Score* player2score;
	Player2Lives* player2lives;
	HighScore* highscore;
	HighScoreList* hsList;
	Text* pText;
	GameOver* pGameOver;
	CentralManager* pCentral;

public:
	static void InitialDisplay() { Instance().privInitialDisplay(); }
	static void OnePlayerDisplay() { Instance().privOnePlayerDisplay(); }
	static void TwoPlayerDisplay() { Instance().privTwoPlayerDisplay(); }
	static void ResetDisplay() { Instance().privResetDisplay(); }
	static void GameOverDisplay() { Instance().privGameOverDisplay(); }

	static void UpdateP1Score() { Instance().privUpdateP1Score(); }
	static void UpdateP1Lives() { Instance().privUpdateP1Lives(); }

	static void UpdateP2Score() { Instance().privUpdateP2Score(); }
	static void UpdateP2Lives() { Instance().privUpdateP2Lives(); }

	static void UpdateHighScore(int score) { Instance().privUpdateHighScore(score); }
	static void UpdateHighScoreList(int p1score, int p2score) { Instance().privUpdateHighScoreList(p1score, p2score); }

	static void SetCentralManager(CentralManager* cm) { Instance().privSetCentralManager(cm); }
	static CentralManager* GetCentralManager() { return Instance().privGetCentralManager(); }

	static void Terminate();
	
};

#endif _HUD
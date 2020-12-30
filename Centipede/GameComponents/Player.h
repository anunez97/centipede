// Player

#ifndef _Player
#define _Player

class Blaster;
class MushroomField;
class PlayerManager;
class Controller;
class Grid;

class Player
{
public:
	Player();
	Player(Player& other) = delete;
	Player& operator=(Player& other) = delete;
	~Player();

	MushroomField* GetField();
	Blaster* GetBlaster();
	Grid* GetGrid();
	int GetScore();
	int GetWave();
	int GetLives();

	void AddScore(int val);
	void AddLife();
	void PlayerDeath();
	void SetController(Controller*);
	void Initialize();
	void Deinitialize();
	void SetWave(int w);

private:
	Blaster* pBlaster;
	MushroomField* pField;
	Controller* pController;
	Grid* pGrid;

	int score;
	int lives;
	int wave;
};

#endif _Player
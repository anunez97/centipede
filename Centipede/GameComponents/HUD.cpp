// HUD

#include "HUD.h"
#include "HighScoreList.h"
#include "HighScore.h"
#include "Player1Score.h"
#include "Player1Lives.h"
#include "Player2Score.h"
#include "Player2Lives.h"
#include "Text.h"

#include "PlayerManager.h"

#include "Grid.h"
#include "Settings.h"
#include "GameOver.h"

HUD* HUD::ptrInstance = nullptr;

HUD::HUD()
	:pCentral(0)
{
	hsList = new HighScoreList;
	highscore = new HighScore;
	player1score = new Player1Score;
	player1lives = new Player1Lives;
	player2score = new Player2Score;
	player2lives = new Player2Lives;
	pText = new Text;
	pGameOver = new GameOver;
}

void HUD::privInitialDisplay()
{
	player1score->Display();

	player2score->Display();

	hsList->Display();
	highscore->Display(hsList->GetHighScore());

	pText->Display();
}

void HUD::privOnePlayerDisplay()
{
	hsList->RemoveList();
	pText->Reset();
	pGameOver->Reset();
	player2score->Reset();

	//player1lives->Display();
	player1lives->UpdateLives(PlayerManager::GetP1Lives());
}

void HUD::privTwoPlayerDisplay()
{
	// Remove the high score list and the text
	hsList->RemoveList();
	pText->Reset();
	pGameOver->Reset();

	player1lives->Display();
	player1lives->UpdateLives(PlayerManager::GetP1Lives());
	player2lives->UpdateLives(PlayerManager::GetP2Lives());
}

void HUD::privGameOverDisplay()
{
	player1score->Display();
	player2score->Display();
	hsList->Display();
	highscore->Display(hsList->GetHighScore());
	pText->Display();
	pGameOver->Display();
}

void HUD::privSPlayerDisplay()
{
	// Remove the highscore list and player 2 score and lives
	hsList->RemoveList();
	player2score->Reset();
	player2lives->Reset();
	pText->Reset();

	player1lives->UpdateLives(PlayerManager::GetP1Lives());
}

void HUD::privResetDisplay()
{
	player1score->Reset();
	player1lives->Reset();
	player2score->Reset();
	player2lives->Reset();
	highscore->Reset();
	hsList->RemoveList();
	pText->Reset();
	pGameOver->Reset();
}

void HUD::privUpdateP1Score()
{
	player1score->UpdateScore(PlayerManager::GetP1Score());
	privUpdateHighScore(PlayerManager::GetP1Score());
}

void HUD::privUpdateP1Lives()
{
	int lives = PlayerManager::GetP1Lives();
	player1lives->UpdateLives(lives);
}

void HUD::privUpdateP2Score()
{
	player2score->UpdateScore(PlayerManager::GetP2Score());
	privUpdateHighScore(PlayerManager::GetP2Score());
}

void HUD::privUpdateP2Lives()
{
	int lives = PlayerManager::GetP2Lives();

	player2lives->UpdateLives(lives);
}

void HUD::privUpdateHighScore(int score)
{
	highscore->UpdateScore(score);
}

void HUD::privUpdateHighScoreList(int p1score, int p2score)
{
	hsList->UpdateList(p1score, p2score);
}

void HUD::privSetCentralManager(CentralManager* cm)
{
	pCentral = cm;
}

CentralManager* HUD::privGetCentralManager()
{
	return pCentral;
}

void HUD::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
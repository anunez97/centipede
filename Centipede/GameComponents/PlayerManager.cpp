// Player Manager

#include "PlayerManager.h"
#include "KeyboardController.h"
#include "AIController.h"
#include "Settings.h"
#include "Grid.h"
#include "Player.h"
#include "MushroomField.h"
#include "HUD.h"
#include "WaveManager.h"
#include "MushroomRegen.h"
#include "ScoreManager.h"
#include "CentralManager.h"
#include "SoundManager.h"

PlayerManager* PlayerManager::ptrInstance = nullptr;

PlayerManager::PlayerManager()
	:pController(0), pCurrPlayer(0), pPlayer1(0), pCurrField(0), pPlayer2(0), pPlayerAI(0), pCentral(0), ScoreBonus(12000), 
	multiplyBonus(1)
{
	pAIController = new AIController;
	pKeyboardController = new KeyboardController;

	pController = pAIController;
}

void PlayerManager::privSetController(Controller* c)
{
	pController = c;
}

void PlayerManager::privSetCentral(CentralManager* cm)
{
	pCentral = cm;
}

void PlayerManager::privCreatePlayer()
{
	pController->Disable();
	pController = pKeyboardController;

	// If there isn't a player 1 create it
	if (!pPlayer1)
	{
		//pCurrPlayer->Deinitialize();
		pPlayer1 = new Player;
		pPlayer1->SetController(pController);
		pCurrPlayer = pPlayer1;
		pCurrPlayer->Initialize();
		pCurrField = pCurrPlayer->GetField();
	}
	// Create a player 2
	else if (!pPlayer2)
	{
		pPlayer2 = new Player;
		pPlayer2->SetController(pController);
	}
}

void PlayerManager::privCreateAI()
{
	// Set the controller to the AI
	pController->Disable();
	pController = pAIController;

	// Make the AI player
	if (!pPlayerAI)
		pPlayerAI = new Player;

	pPlayerAI->SetController(pController);

	pCurrPlayer = pPlayerAI;
	pCurrField = pCurrPlayer->GetField();
}

void PlayerManager::privStartAI()
{
	SoundManager::Mute();

	// Set the current player to the AI
	pCurrPlayer = pPlayerAI;
	pCurrField = pPlayerAI->GetField();
	pPlayerAI->Initialize();

	// Set the wave manager to the AI's field
	WaveManager::SetField(pCurrPlayer->GetField());
	
}

void PlayerManager::privResetAI()
{
	pPlayerAI->Deinitialize();
	delete pPlayerAI;
	pPlayerAI = 0;
}

void PlayerManager::privSwitchPlayer()
{
	// End the current players wave
	WaveManager::EndWave();

	// If in Attractor Mode
	if (pCurrPlayer == pPlayerAI)
	{
		RespawnPlayer();
	}
	// If in 1 Player Mode
	else if (pPlayer2 == 0)
	{
		// If the player runs out of lives
		if (pCurrPlayer->GetLives() == 0)
		{
			//ConsoleMsg::WriteLine("Game Over");

			// Update the highscore list with the player's score
			HUD::UpdateHighScoreList(pPlayer1->GetScore(), 0);

			// Remove the player
			pCurrPlayer->Deinitialize();
			delete pPlayer1;
			pPlayer1 = 0;

			// Clear the HUD
			HUD::ResetDisplay();

			// Create the AI player
			CreateAI();

			// Update the highscore list
			HUD::GameOverDisplay();
			
			StartAI();
		}
		// Still has lives left
		else
		{
			RespawnPlayer();
			HUD::UpdateP1Lives();
		}
	}
	// 2 player mode
	else
	{
		// If both players run out of lives 
		if (pPlayer1->GetLives() == 0 && pPlayer2->GetLives() == 0)
		{

			//Update the high score
			HUD::UpdateHighScoreList(pPlayer1->GetScore(), pPlayer2->GetScore());

			// Remove the players
			pCurrPlayer->Deinitialize();
			delete pPlayer1;
			delete pPlayer2;
			pPlayer1 = 0;
			pPlayer2 = 0;

			// Reset the HUD
			HUD::ResetDisplay();

			// Create the AI
			CreateAI();

			// Display the Game Over Screen
			HUD::GameOverDisplay();

			// Start the AI
			StartAI();
		}
		// Switching to Player 2
		else if (pCurrPlayer == pPlayer1 && pPlayer2->GetLives() > 0)
		{
			//ConsoleMsg::WriteLine("Switching to Player 2");
			pCurrPlayer->Deinitialize();
			pCurrPlayer = pPlayer2;

			pCurrField = pCurrPlayer->GetField();
			pCurrPlayer->Initialize();
			HUD::UpdateP2Lives();
		}
		// Switching to Player 1
		else if (pCurrPlayer == pPlayer2 && pPlayer1->GetLives() > 0)
		{
			//ConsoleMsg::WriteLine("Switching to Player 1");
			pCurrPlayer->Deinitialize();

			pCurrPlayer = pPlayer1;
			pCurrField = pCurrPlayer->GetField();
			pCurrPlayer->Initialize();
			HUD::UpdateP1Lives();
		}
		// If the current player is the only one with lives left
		else
		{
			RespawnPlayer();
			HUD::UpdateP1Lives();
			HUD::UpdateP2Lives();
		}
	}
	WaveManager::SetField(pCurrPlayer->GetField());
	WaveManager::StartNextWave();
}

void PlayerManager::privAddScore(int val)
{
	pCurrPlayer->AddScore(val);

	// if the player's score is more than a multiple of the Score Bonus, gain a life
	if (pCurrPlayer->GetScore() > (ScoreBonus * multiplyBonus))
	{
		pCurrPlayer->AddLife();

		// Variable used to calculate the next multiple of the Score Bonus
		multiplyBonus = (pCurrPlayer->GetScore() / ScoreBonus) + 1;
	}

	if (pCurrPlayer == pPlayer1)
	{
		HUD::UpdateP1Score();
		HUD::UpdateP1Lives();
		
	}
	else if (pCurrPlayer == pPlayer2)
	{
		HUD::UpdateP2Score();
		HUD::UpdateP2Lives();
	}
}

void PlayerManager::RespawnPlayer()
{
	pCurrPlayer->Initialize();

	pController->SetBlaster(pCurrPlayer->GetBlaster());
	pController->Enable();
}

void PlayerManager::RespawnAI()
{
	pCurrPlayer->Initialize();

	pController->SetBlaster(pCurrPlayer->GetBlaster());
	pController->Enable();
}

MushroomField* PlayerManager::privGetCurrentField()
{
	return pCurrPlayer->GetField();
}

Grid* PlayerManager::privGetCurrentGrid()
{
	return pCurrPlayer->GetGrid();
}

int PlayerManager::privGetP1Score()
{
	return pPlayer1->GetScore();
}

int PlayerManager::privGetP2Score()
{
	return pPlayer2->GetScore();
}

int PlayerManager::privGetP1Lives()
{
	return pPlayer1->GetLives();
}

int PlayerManager::privGetP2Lives()
{
	return pPlayer2->GetLives();
}

int PlayerManager::privGetCurrentWave()
{
	return pCurrPlayer->GetWave();
}

void PlayerManager::privIncreaseCurrentWave()
{
	pCurrPlayer->SetWave(pCurrPlayer->GetWave() + 1);
}

void PlayerManager::privTerminate()
{
	delete pPlayer1;
	delete pPlayer2;
	delete pPlayerAI;

	delete ptrInstance;

	ptrInstance = nullptr;
}
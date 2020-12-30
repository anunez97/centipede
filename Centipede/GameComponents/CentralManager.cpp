// Central Manager

#include "CentralManager.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "PlayerManager.h"
#include "WaveManager.h"

#include "SpiderManager.h"
#include "ScorpionManager.h"
#include "MushroomField.h"

#include "HUD.h"

CentralManager::CentralManager()
{
	RegisterInput(InputFlags::KeyPressed);

	// Load the wave data from file
	WaveManager::GetWaveInfo();

	// Create the AI and start it
	PlayerManager::CreateAI();

	// Initialize the HUD
	HUD::InitialDisplay();

	// Start the AI
	HUD::SetCentralManager(this);

	PlayerManager::StartAI();

	WaveManager::StartNextWave();

}

void CentralManager::Update()
{
	ScoreManager::ProcessScores();
	SoundManager::ProcessSounds();
}

void CentralManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrKey, bool shiftKey, bool systemKey)
{
	// 1 Player Mode
	if (k == sf::Keyboard::Numpad1)
	{
		// Turn on sounds
		SoundManager::Unmute();

		// Resets the wave
		WaveManager::EndWave();

		// Turn off the AI
		PlayerManager::ResetAI();

		// Create the Player
		PlayerManager::CreatePlayer();

		// Set the Player's field to the wave manager then start the first wave
		WaveManager::SetField(PlayerManager::GetCurrentField());
		WaveManager::StartNextWave();

		// Set the HUD to One Player Mode
		HUD::OnePlayerDisplay();

		DeregisterInput();
	}
	// 2 Player Mode
	else if (k == sf::Keyboard::Numpad2)
	{
		// Turn on sounds
		SoundManager::Unmute();

		// Reset the wave
		WaveManager::EndWave();

		// Turn off the AI
		PlayerManager::ResetAI();

		// Create both players
		PlayerManager::CreatePlayer();
		PlayerManager::CreatePlayer();

		// Set the field to the wave manager
		WaveManager::SetField(PlayerManager::GetCurrentField());
		WaveManager::StartNextWave();

		// Updates HUD to start 
		HUD::TwoPlayerDisplay();

		DeregisterInput();
	}
}

void CentralManager::Enable()
{
	RegisterInput(InputFlags::KeyPressed);
}
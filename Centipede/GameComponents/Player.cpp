// Player

#include "Player.h"
#include "MushroomField.h"
#include "BlasterFactory.h"
#include "Settings.h"
#include "Grid.h"
#include "PlayerManager.h"
#include "KeyboardController.h"
#include "Blaster.h"

Player::Player()
	:lives(3), score(0), pController(0), pBlaster(0), wave(1)
{
	pGrid = new Grid;
	pField = new MushroomField;
	pField->SetGrid(pGrid);
}

Player::~Player()
{
	delete pGrid;
	delete pField;
}

void Player::SetController(Controller* c)
{
	pController = c;
}

void Player::Initialize()
{
	pField->Initialize();
	pBlaster = BlasterFactory::CreateBlaster(
		sf::Vector2f(WindowManager::Window().getDefaultView().getSize().x / 2.0f, Grid::gridtoPixels(Settings::BROWBORDER)), this);
	pController->SetBlaster(pBlaster);
	pController->Enable();
	lives--;
}

void Player::Deinitialize()
{
	pField->Deinitialize();
	pController->Disable();
	pBlaster->MarkForDestroy();
}

void Player::SetWave(int w)
{
	wave = w;
}

MushroomField* Player::GetField()
{
	return pField;
}

Blaster* Player::GetBlaster()
{
	return pBlaster;
}

Grid* Player::GetGrid()
{
	return pGrid;
}

int Player::GetScore()
{
	return score;
}

int Player::GetWave()
{
	return wave;
}

int Player::GetLives()
{
	return lives;
}

void Player::AddScore(int val)
{
	score += val;
}

void Player::AddLife()
{
	lives++;
}

void Player::PlayerDeath()
{
	BlasterFactory::PlayerDeath();
	pController->Disable();
	pController->SetBlaster(0);
	PlayerManager::SwitchPlayer();
}
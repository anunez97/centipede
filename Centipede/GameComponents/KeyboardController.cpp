// Keyboard Controller

#include "KeyboardController.h"
#include "BlasterFactory.h"
#include "Settings.h"
#include "Grid.h"
#include "Blaster.h"

KeyboardController::KeyboardController()
	:pBlaster(0)
{
}

KeyboardController::~KeyboardController()
{
	pBlaster = 0;
}

void KeyboardController::SetBlaster(Blaster* b)
{
	pBlaster = b;
}

void KeyboardController::Disable()
{
	DeregisterInput();
}

void KeyboardController::Enable()
{
	RegisterInput(InputFlags::KeyPressed);
}

void KeyboardController::Update()
{
	// Movement
	if (pBlaster)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			pBlaster->move(sf::Vector2f(-2.0f, 0.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			pBlaster->move(sf::Vector2f(2.0f, 0.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			pBlaster->move(sf::Vector2f(0.0f, -2.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			pBlaster->move(sf::Vector2f(0.0f, 2.0f));

		// Fire a bullet
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			pBlaster->fire();
	}
}

void KeyboardController::Destroy()
{
	DeregisterInput();
}
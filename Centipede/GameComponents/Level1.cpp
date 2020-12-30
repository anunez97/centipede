// CentipedeLevel
// Andre Berthiaume, MArch 2013

#include "TEAL\CommonElements.h"

#include "Level1.h"
#include "Ship.h"
#include "Bullet.h"
#include "GameController.h"
#include "Blaster.h"

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,0,255) );

	//new Ship;
	new Blaster;

	//CollisionTestPair<Bullet,Mushroom>();

};

void Level1::Terminate()
{
	GameController::Terminate();
}
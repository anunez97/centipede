// Explosion

#include "Explosion.h"

Explosion::Explosion()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Explosion"), 8, 2, 15.0f, 0, 16, false, false);

	SetDrawOrder(999);
}

void Explosion::Update()
{
	MainSprite.Update();
	if (MainSprite.IsLastAnimationFrame())
		MarkForDestroy();
}

void Explosion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Explosion::Destroy()
{

}

void Explosion::Initialize(sf::Vector2f pos)
{
	Pos = pos;
	MainSprite.setPosition(Pos);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.SetFrame(0);
	MainSprite.SetAnimation(8, 15, true, false);
}
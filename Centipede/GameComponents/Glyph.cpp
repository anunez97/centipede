// Glyph

#include "Glyph.h"
#include "Spritesheet.h"
#include "TEAL/ResourceManager.h"
#include "Settings.h"
#include <assert.h>

Glyph::Glyph()
{
	sprsheet = nullptr;
	cellIndex = 0;
	Pos = sf::Vector2f(0.0f, 0.0f);

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0f, 0, 7, false, false);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(Settings::CELL_SIZE / MainSprite.getTextureRect().width, Settings::CELL_SIZE / MainSprite.getTextureRect().height);

	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
}

void Glyph::Initialize(Spritesheet* sheet, int cellInd, sf::Vector2f pos)
{
	sprsheet = sheet;
	cellIndex = cellInd;
	Pos = pos;

	MainSprite.setPosition(Pos);

	SetCollider(MainSprite, *bitmap);
	RegisterCollision<Glyph>(*this);
}

void Glyph::Draw()
{
	assert(sprsheet != nullptr);

	sprsheet->Draw(cellIndex, Pos);
}

void Glyph::Destroy()
{
	DeregisterCollision<Glyph>(*this);
}

sf::Vector2f Glyph::GetPos()
{
	return Pos;
}
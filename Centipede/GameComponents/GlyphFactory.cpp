// Glyph Factory

#include "GlyphFactory.h"
#include "GlyphObjectPool.h"
#include "Glyph.h"

GlyphFactory* GlyphFactory::ptrInstance = nullptr;

Glyph* GlyphFactory::privCreateGlyph(Spritesheet* sheet, int cellInd, sf::Vector2f pos)
{
	Glyph* g = GlyphPool.getGlyph();

	g->SetExternalManagement(RecycleGlyph);

	g->Initialize(sheet, cellInd, pos);

	return g;
}

void GlyphFactory::privRecycleGlyph(GameObject* ob)
{
	GlyphPool.returnGlyph(static_cast<Glyph*>(ob));
}

void GlyphFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
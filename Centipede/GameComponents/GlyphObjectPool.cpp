// Glyph Object Pool

#include "GlyphObjectPool.h"
#include "Glyph.h"

GlyphObjectPool::GlyphObjectPool()
{

}

GlyphObjectPool::~GlyphObjectPool()
{
	while (!recycledGlyphs.empty())
	{
		delete recycledGlyphs.top();
		recycledGlyphs.pop();
	}
}

Glyph* GlyphObjectPool::getGlyph()
{
	Glyph* g;

	if (recycledGlyphs.empty())
	{
		//ConsoleMsg::WriteLine("New Glyph");
		g = new Glyph();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Glyph");
		g = recycledGlyphs.top();
		recycledGlyphs.pop();

		g->RegisterToCurrentScene();
	}

	return g;
}

void GlyphObjectPool::returnGlyph(Glyph* g)
{
	recycledGlyphs.push(static_cast<Glyph*>(g));
	//ConsoleMsg::WriteLine("Recycled Glyph Stack Size: " + Tools::ToString(recycledGlyphs.size()));
}
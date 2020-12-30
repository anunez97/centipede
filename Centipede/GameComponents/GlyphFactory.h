// Glyph Factory

#ifndef _GlyphFactory
#define _GlyphFactory

#include "TEAL/CommonElements.h"
#include "GlyphObjectPool.h"
#include "Glyph.h"

class GameObject;
class Spritesheet;

class GlyphFactory
{
private:
	// Singleton
	static GlyphFactory* ptrInstance;

	GlyphFactory() = default;
	GlyphFactory(const GlyphFactory&) = delete;
	GlyphFactory& operator=(const GlyphFactory&) = delete;
	~GlyphFactory() = default;

	static GlyphFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new GlyphFactory();
		return *ptrInstance;
	}

	GlyphObjectPool GlyphPool;

	Glyph* privCreateGlyph(Spritesheet* sheet, int cellInd, sf::Vector2f pos);
	void privRecycleGlyph(GameObject* b);

public:
	static Glyph* CreateGlyph(Spritesheet* sheet, int cellInd, sf::Vector2f pos) { return Instance().privCreateGlyph(sheet, cellInd, pos); }
	static void RecycleGlyph(GameObject* b) { Instance().privRecycleGlyph(b); }

	static void Terminate();

};

#endif _GlyphFactory
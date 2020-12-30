// Glyph Object Pool

#ifndef _GlyphObjectPool
#define _GlyphObjectPool

#include "TEAL/CommonElements.h"
#include <stack>

class Glyph;

class GlyphObjectPool
{
public:
	GlyphObjectPool();
	GlyphObjectPool(GlyphObjectPool& other) = delete;
	GlyphObjectPool& operator=(GlyphObjectPool& other) = delete;
	~GlyphObjectPool();

	Glyph* getGlyph();
	void returnGlyph(Glyph*);

private:
	std::stack<Glyph*> recycledGlyphs;
};

#endif _GlyphObjectPool
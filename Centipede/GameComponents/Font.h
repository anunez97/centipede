// Font

#ifndef _Font
#define _Font

#include "Spritesheet.h"

class Font : public Spritesheet
{
public:
	Font();
	Font(Font& other) = delete;
	Font& operator=(Font& other) = delete;
	virtual ~Font() = default;

private:
	virtual int CharToIndex(char& c);
};

#endif _Font
/*// Mushroom Generator

#include "TEAL/CommonElements.h"
#include "MushroomField.h"

class MushroomGenerator
{
public:
	MushroomGenerator() = default;
	MushroomGenerator(MushroomGenerator& other) = delete;
	MushroomGenerator& operator=(MushroomGenerator& other) = delete;
	~MushroomGenerator() = default;
	MushroomGenerator(MushroomField*);

	void generateField();
	void setField(MushroomField*);
	void terminateField();

private:
	MushroomField* mfield;
};*/
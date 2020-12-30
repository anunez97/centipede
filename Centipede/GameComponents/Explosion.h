// Explosion

#ifndef _Explosion
#define _Explosion

#include "TEAL\CommonElements.h"

class Explosion : public GameObject
{
public:
	Explosion();
	Explosion(Explosion& other) = delete;
	Explosion& operator=(Explosion& other) = delete;
	~Explosion() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Initialize(sf::Vector2f pos);

private:
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;
};


#endif _Explosion
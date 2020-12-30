// Central Manager

#ifndef _CentralManager
#define _CentralManager

#include "TEAL/CommonElements.h"

class CentralManager : public GameObject
{
public:
	CentralManager();
	CentralManager(CentralManager& other) = delete;
	CentralManager& operator=(CentralManager& other) = delete;
	~CentralManager() = default;

	virtual void Update();
	virtual void KeyPressed(sf::Keyboard::Key, bool altKey, bool ctrKey, bool shiftKey, bool systemKey);

	void Enable();
};

#endif _CentralManager
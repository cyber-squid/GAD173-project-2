#pragma once

#include "app.h"
#include "tiles.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;
	Tiles MapTiles;
	int tileIDSelected = 0;
};

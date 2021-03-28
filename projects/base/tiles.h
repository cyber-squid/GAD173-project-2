#include <SFML/Graphics.hpp>
#pragma once

#define TILE_ARRAY_SIZE 72
class Tiles
{
public:

	Tiles();
	~Tiles();

	//sf::Texture* catTexture;
	//sf::Sprite kitty;

	sf::Texture* redBlockTexture;
	sf::Texture* blueBlockTexture;
	sf::Texture* greenBlockTexture;
	//sf::Texture* yellowBlockTexture;
	sf::Texture* errorBlockTexture;
	

	sf::Sprite tileset[TILE_ARRAY_SIZE];

	int saveMap[TILE_ARRAY_SIZE]{
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0
	};

};
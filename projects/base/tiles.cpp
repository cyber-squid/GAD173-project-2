#include "kage2dutil/texture_manager.h"
#include "tiles.h"

/// <summary>
/// Handles the map's tiles and their sprites.
/// </summary>
Tiles::Tiles()
{
	//catTexture = kage::TextureManager::getTexture("data/cat.png");
	//kitty.setTexture(*catTexture);

	redBlockTexture = kage::TextureManager::getTexture("data/breakout/redbreakoutblock.png");
	blueBlockTexture = kage::TextureManager::getTexture("data/breakout/bluebreakoutblock.png");
	greenBlockTexture = kage::TextureManager::getTexture("data/breakout/greenbreakoutblock.png");
	//yellowBlockTexture = kage::TextureManager::getTexture("data/breakout/yellowbreakoutblock.png");
	errorBlockTexture = kage::TextureManager::getTexture("data/breakout/errorbreakoutblock.png");
}

Tiles::~Tiles()
{

}
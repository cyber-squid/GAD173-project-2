#include "example.h"
#include "grid.h"
#include "tiles.h"

Example::Example(): App()
{
	
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	//Tiles MapTiles;
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	// two loops that print all saved tiles on the x and x axes
	
	for (size_t y = 0; y < Y_LINES_AMNT - 1; y++)
	{
		for (size_t x = 0; x < X_LINES_AMNT - 1; x++) 
		{
			int i = x + y * (X_LINES_AMNT - 1); // formula for finding the position of the tile
			
			// assigns a sprite to the tile based on the value saved to the associated grid space
			if (MapTiles.saveMap[i] == 1)
			{
				MapTiles.tileset[i].setTexture(*MapTiles.redBlockTexture);
				MapTiles.saveMap[i] = 1;
			}

			if (MapTiles.saveMap[i] == 2)
			{
				MapTiles.tileset[i].setTexture(*MapTiles.blueBlockTexture);
				MapTiles.saveMap[i] = 2;
			}

			if (MapTiles.saveMap[i] == 3)
			{
				MapTiles.tileset[i].setTexture(*MapTiles.greenBlockTexture);
				MapTiles.saveMap[i] = 3;
			}
			else
			{
				// failsafe in case the value saved isn't in the above registry for whatever reason
			}
			
			MapTiles.tileset[i].setScale(1.9, 1.9999);
			MapTiles.tileset[i].setPosition(
				sf::Vector2f(x * CELL_WIDTH + GRID_OFFSET_X,
					y * CELL_HEIGHT + GRID_OFFSET_Y));
			// each time this loop completes it incerements the main loop,
			// and the position and instance of tile depend on how far into
			// the loop the processor is, so the tiles are printed row by row.
		}
	}
	
	return true;
}

void Example::update(float deltaT)
{	
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	
	
	ImGui::Begin("Options"); 
	if (ImGui::Button("Eraser"))
	{
		tileIDSelected = 0;
	}
	if (ImGui::ImageButton(*MapTiles.redBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 1;
	}
	if (ImGui::ImageButton(*MapTiles.blueBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 2;
	}
	if (ImGui::ImageButton(*MapTiles.greenBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 3;
	}
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();


	//how it should work:
	//-if mouse clicked, get x and y
	//-divide x and y by width and height
	//-cast them to ints to keep accuracy, then use the formula x + y * x cell count
	//-use this to determine index number for the grid tile and load the selected sprite
	//to the corresponding index no.  depending on which tile type the player selected
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window); 
	
	if (
		mousePos.x >= GRID_OFFSET_X && mousePos.x <= Y_LINES_AMNT *  CELL_WIDTH 
			&& mousePos.y >= GRID_OFFSET_Y && mousePos.y <= X_LINES_AMNT * CELL_HEIGHT 
				&& sf::Mouse::isButtonPressed(sf::Mouse::Left) )
	{
	
		int mouseCellX = ((mousePos.x - GRID_OFFSET_X) / CELL_WIDTH); 
		int mouseCellY = ((mousePos.y - GRID_OFFSET_Y) / CELL_HEIGHT);

		int selectedSquare = mouseCellX + mouseCellY  * (X_LINES_AMNT - 1);
		//std::cout << selectedSquare << std::endl;
		
		if (tileIDSelected == 0)
		{
			MapTiles.tileset[selectedSquare].setTexture(*MapTiles.errorBlockTexture);
			MapTiles.tileset[selectedSquare].setColor(sf::Color(255, 255, 255, 0));
			MapTiles.saveMap[selectedSquare] = 0;
		}
		if (tileIDSelected == 1)
		{
			MapTiles.tileset[selectedSquare].setTexture(*MapTiles.redBlockTexture);
			MapTiles.tileset[selectedSquare].setColor(sf::Color(255, 255, 255, 255));
			MapTiles.saveMap[selectedSquare] = 1;
		}
		if (tileIDSelected == 2)
		{
			MapTiles.tileset[selectedSquare].setTexture(*MapTiles.blueBlockTexture);
			MapTiles.tileset[selectedSquare].setColor(sf::Color(255, 255, 255, 255));
			MapTiles.saveMap[selectedSquare] = 2;
		}
		if (tileIDSelected == 3)
		{
			MapTiles.tileset[selectedSquare].setTexture(*MapTiles.greenBlockTexture);
			MapTiles.tileset[selectedSquare].setColor(sf::Color(255, 255, 255, 255));
			MapTiles.saveMap[selectedSquare] = 3;
		}
	}

	
}

void Example::render()
{
	Grid LineGrid;
	m_window.draw(*m_backgroundSprite);
	
	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		m_window.draw(MapTiles.tileset[i]);
	}

	LineGrid.Draw(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}


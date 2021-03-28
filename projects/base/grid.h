#include <SFML/Graphics.hpp>
#pragma once

#define X_LINES_AMNT 9
#define Y_LINES_AMNT 9

#define LINE_WIDTH 2
#define X_LINE_LENGTH 800
#define Y_LINE_LENGTH 400

#define GRID_OFFSET_X 40
#define GRID_OFFSET_Y 50

#define CELL_HEIGHT 50
#define CELL_WIDTH 100

/// <summary>
/// Responsible for generating and rendering the lines of the tile editor grid.
/// </summary>
class Grid
{

public:

	Grid();
	~Grid();
	void Draw(sf::RenderWindow& window);

	int CellCountX = X_LINES_AMNT - 1;
	int CellCountY = Y_LINES_AMNT - 1;
	
	sf::RectangleShape HorizLines[X_LINES_AMNT];
	sf::RectangleShape VertiLines[Y_LINES_AMNT];

};


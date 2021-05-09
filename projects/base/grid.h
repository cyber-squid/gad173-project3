#include <SFML/Graphics.hpp>
#pragma once

#define CELL_COUNT_X 8
#define CELL_COUNT_Y 8

#define CELL_WIDTH 100
#define CELL_HEIGHT 50

#define X_LINES_AMNT   CELL_COUNT_X + 1
#define Y_LINES_AMNT   CELL_COUNT_Y + 1

#define LINE_WIDTH 2

#define X_LINE_LENGTH   CELL_WIDTH * CELL_COUNT_X
#define Y_LINE_LENGTH   CELL_HEIGHT * CELL_COUNT_Y

#define GRID_OFFSET_X 40
#define GRID_OFFSET_Y 40


/// <summary>
/// Responsible for generating and rendering the lines of the tile editor grid.
/// Also has #define preprocessors used in other files to help make each aspect more dynamic and easier to edit.
/// </summary>
class Grid
{

public:

	Grid();
	~Grid();
	void Draw(sf::RenderWindow& window);

	int CellCountX = X_LINES_AMNT - 1;
	int CellCountY = Y_LINES_AMNT - 1;
	
	sf::RectangleShape HorizLines[Y_LINES_AMNT];
	sf::RectangleShape VertiLines[X_LINES_AMNT];

	sf::RectangleShape GridBackground;

};
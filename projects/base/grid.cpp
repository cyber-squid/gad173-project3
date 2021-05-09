#include <iostream>
#include "grid.h"

Grid::Grid()
{
	GridBackground.setSize(sf::Vector2f(X_LINE_LENGTH, Y_LINE_LENGTH));
	GridBackground.setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y));
	GridBackground.setFillColor(sf::Color(0, 0, 0, 110));

	for (size_t i = 0; i < Y_LINES_AMNT; i++) // initialises and sets the positions of the horizontal grid lines.
	{
		
		HorizLines[i] = sf::RectangleShape();
		HorizLines[i].setSize(sf::Vector2f(X_LINE_LENGTH, LINE_WIDTH));
		HorizLines[i].setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y + (i * CELL_HEIGHT)));
	}
	
	for (size_t i = 0; i < X_LINES_AMNT; i++) // same for vertical grid lines.
	{
		VertiLines[i] = sf::RectangleShape();
		VertiLines[i].setSize(sf::Vector2f(LINE_WIDTH, Y_LINE_LENGTH));
		VertiLines[i].setPosition(sf::Vector2f(GRID_OFFSET_X + i * CELL_WIDTH, GRID_OFFSET_Y));
	}
}

Grid::~Grid()
{
	
}

void Grid::Draw(sf::RenderWindow& window) // renders the lines in the window given in the parameter. 
{
	for (size_t i = 0; i < Y_LINES_AMNT; i++)
	{
		window.draw(HorizLines[i]);
	}
	for (size_t i = 0; i < X_LINES_AMNT; i++)
	{
		window.draw(VertiLines[i]);
	}
}
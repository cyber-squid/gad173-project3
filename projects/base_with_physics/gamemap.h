#pragma once
#include <SFML/Graphics.hpp>
#include "gametile.h"

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

#define TILE_WIDTH 53
#define TILE_HEIGHT 25

#define TILE_ARRAY_SIZE 72

/// <summary>
/// Responsible for aspects of the tile system. This holds the array representing tile types in the save file,
/// as well as textures for each tile in the Tile array. 
/// setting up the tiles on the grid when PrintCurrentSave() is called. 
/// </summary>
class GameMap
{
public:

	GameMap();
	~GameMap();

	void LoadTileTextures();
	void PrintCurrentSave();

	int tileIDSelected = 0;

	//sf::Texture* redBlockTexture;
	//sf::Texture* blueBlockTexture;
	//sf::Texture* greenBlockTexture;
	//sf::Texture* yellowBlockTexture;
	//sf::Texture* errorBlockTexture;

	sf::Texture* blueBlockTilesheet;
	sf::Texture* redBlockTilesheet;
	sf::Texture* greenBlockTilesheet;
	sf::Texture* yellowBlockTilesheet;

	sf::Sprite tileset[TILE_ARRAY_SIZE];

	GameTile tiles[TILE_ARRAY_SIZE];

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


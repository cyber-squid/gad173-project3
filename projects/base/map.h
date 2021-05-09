#pragma once
#include <SFML/Graphics.hpp>
#include "tile.h"

#define TILE_WIDTH 53
#define TILE_HEIGHT 25

#define TILE_ARRAY_SIZE 72

/// <summary>
/// Responsible for aspects of the tile system. This holds the array representing tile types in the save file,
/// as well as textures for each tile in the Tile array. 
/// setting up the tiles on the grid when PrintCurrentSave() is called. 
/// </summary>
class Map
{
public:

	Map();
	~Map();

	void PrintCurrentSave();
	void GetMousePosOnGrid(sf::RenderWindow& window);
	void PrintTileID();
	int tileIDSelected = 0;

	sf::Texture* redBlockTexture;
	sf::Texture* blueBlockTexture;
	sf::Texture* greenBlockTexture;
	sf::Texture* yellowBlockTexture;
	sf::Texture* errorBlockTexture;

	sf::Texture* blueBlockTilesheet; 
	sf::Texture* redBlockTilesheet;
	sf::Texture* greenBlockTilesheet;
	sf::Texture* yellowBlockTilesheet;

	sf::Sprite tileset[TILE_ARRAY_SIZE];

	Tile tiles[TILE_ARRAY_SIZE];

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


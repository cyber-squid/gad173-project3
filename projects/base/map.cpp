#include <iostream>
#include "kage2dutil/texture_manager.h"
#include "map.h"

Map::Map()
{
	redBlockTexture = kage::TextureManager::getTexture("data/breakout/redbreakoutblock.png");
	blueBlockTexture = kage::TextureManager::getTexture("data/breakout/bluebreakoutblock.png");
	greenBlockTexture = kage::TextureManager::getTexture("data/breakout/greenbreakoutblock.png");
	yellowBlockTexture = kage::TextureManager::getTexture("data/breakout/yellowbreakoutblock.png");
	errorBlockTexture = kage::TextureManager::getTexture("data/breakout/errorbreakoutblock.png");

	blueBlockTilesheet = kage::TextureManager::getTexture("data/breakout/blueblockspritesheet.png");
	redBlockTilesheet = kage::TextureManager::getTexture("data/breakout/redblockspritesheet.png");
	greenBlockTilesheet = kage::TextureManager::getTexture("data/breakout/greenblockspritesheet.png");
	yellowBlockTilesheet = kage::TextureManager::getTexture("data/breakout/yellowblockspritesheet.png");
}

Map::~Map()
{

}

void Map::PrintCurrentSave()
{
	// two loops that print all saved tiles on the x and x axes

	for (size_t y = 0; y < Y_LINES_AMNT - 1; y++)
	{
		for (size_t x = 0; x < X_LINES_AMNT - 1; x++)
		{
			int i = x + y * (X_LINES_AMNT - 1); // formula for finding the position of the tile

			//std::cout << i << std::endl;
			// assigns a sprite to the tile based on the value saved to the associated grid space
			if (saveMap[i] == 0)
			{
				tiles[i].tileID = 0;
				tiles[i].Load(blueBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
				tiles[i].spritesheet.setColor(sf::Color(255, 255, 255, 0));
				//saveMap[i] = 0;
			}
			if (saveMap[i] == 1)
			{
				tiles[i].tileID = 1;
				tiles[i].Load(redBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
				tiles[i].spritesheet.setColor(sf::Color(255, 255, 255, 255));
				//saveMap[i] = 1;
			}
			if (saveMap[i] == 2)
			{
				tiles[i].tileID = 2;
				tiles[i].Load(blueBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
				tiles[i].spritesheet.setColor(sf::Color(255, 255, 255, 255));
				//saveMap[i] = 2;
			}
			if (saveMap[i] == 3)
			{
				tiles[i].tileID = 3;
				tiles[i].Load(greenBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
				tiles[i].spritesheet.setColor(sf::Color(255, 255, 255, 255));
				//saveMap[i] = 3;
			}
			if (saveMap[i] == 4)
			{
				tiles[i].tileID = 4;
				tiles[i].Load(yellowBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
				tiles[i].spritesheet.setColor(sf::Color(255, 255, 255, 255));
				//saveMap[i] = 4;
			}
			else
			{
				// failsafe in case the value saved isn't in the above registry for whatever reason
			}

			tiles[i].spritesheet.setScale(1.9, 1.9999);
			//tileset[i].setScale(1.9, 1.9999);
			tiles[i].spritesheet.setPosition(sf::Vector2f(x * CELL_WIDTH + GRID_OFFSET_X,
				y * CELL_HEIGHT + GRID_OFFSET_Y));
			//tileset[i].setPosition(sf::Vector2f(x * CELL_WIDTH + GRID_OFFSET_X,
					//y * CELL_HEIGHT + GRID_OFFSET_Y));
					
			// each time this loop completes it incerements the main loop,
			// and the position and instance of tile depend on how far into
			// the loop the processor is, so the tiles are printed row by row.
		}
	}
}


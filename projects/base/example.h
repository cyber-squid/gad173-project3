#pragma once

#include "app.h"
#include "map.h"
#include "grid.h"
#include "animator.h"

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

	void setBackground(std::string textureFilename);
	sf::Sprite *m_backgroundSprite;
	std::string mapOneSavefileName = "savefile.txt";
	std::string mapTwoSavefileName = "savefile2.txt";
	Grid LineGrid;
	Map MapTiles;

	//Tile exampleTileAnim;
	//sf::Texture* testTexture;

	int tileIDSelected = 0;
};

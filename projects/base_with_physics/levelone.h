#pragma once
#include "scene.h"

class LevelOne : public Scene
{
public:
	LevelOne();
	~LevelOne();

	void Load(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

	sf::Sprite* backgroundSprite;
	
	std::string MapFileOne = "savefile.txt";
};


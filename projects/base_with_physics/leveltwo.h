#pragma once
#include "scene.h"

class LevelTwo : public Scene
{
public:
	LevelTwo();
	~LevelTwo();

	void Load(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

	sf::Sprite* backgroundSprite;

	std::string MapFileTwo = "savefile2.txt";
};


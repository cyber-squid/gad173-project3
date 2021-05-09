#pragma once
#include "scene.h"

class LevelOne : public Scene
{
public:
	LevelOne();
	~LevelOne();

	void Load(sf::RenderWindow& window);
	void Update();
	void Render(sf::RenderWindow& window);

	sf::Sprite* backgroundSprite;
	
};


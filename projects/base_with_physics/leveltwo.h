#pragma once
#include "scene.h"

class LevelTwo : public Scene
{
	LevelTwo();
	~LevelTwo();

	void Load();
	void Update();
	void Render(sf::RenderWindow& window);
};


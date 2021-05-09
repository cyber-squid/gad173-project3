#pragma once
#include "scene.h"

class MainMenu : public Scene
{
public:

	MainMenu();
	~MainMenu();

	void Load(sf::RenderWindow& window);
	void Update();
	void Render(sf::RenderWindow& window);

	sf::Sprite* backgroundSprite;

	sf::Sprite StartButton;
	sf::Texture* StartButtonTexture;
};


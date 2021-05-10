#pragma once
#include "scene.h"
#include "scenemanager.h"

class MainMenu : public Scene
{
public:

	MainMenu();
	~MainMenu();

	void Load(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

	sf::Sprite* backgroundSprite;

	sf::Sprite StartButton;
	sf::Texture* StartButtonTexture;

};


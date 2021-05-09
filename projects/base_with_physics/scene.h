#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Scene
{
public:
	Scene();
	~Scene();

	bool isLoaded = false;
	int Index = 0;

	virtual void Load(sf::RenderWindow& window);
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);

};


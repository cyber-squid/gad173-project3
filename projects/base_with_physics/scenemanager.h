#pragma once
//#include <iostream>
#include "scene.h"


class SceneManager
{
public:

	SceneManager();
	~SceneManager();

	int currentSceneIndex = 0;
	//int previousSceneIndex = 0;

	std::vector <Scene*> scenes;

	void AddScene(Scene* scene);
	void RemoveScene(int sceneIndex);
	void LoadScene(int sceneIndex, sf::RenderWindow& window);

	void UpdateScene(sf::RenderWindow& window);
	void RenderScene(sf::RenderWindow& window);

};


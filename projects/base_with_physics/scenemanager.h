#pragma once
//#include <iostream>
#include "scene.h"


class SceneManager
{
public:

	SceneManager();
	~SceneManager();

	int currentSceneIndex;

	std::vector <Scene*> scenes;

	void AddScene(Scene* scene);
	void RemoveScene(int sceneIndex);
	void LoadScene(int sceneIndex, sf::RenderWindow& window);

	void UpdateScene();
	void RenderScene(sf::RenderWindow& window);

};


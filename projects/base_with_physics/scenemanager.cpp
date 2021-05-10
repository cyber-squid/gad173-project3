#include "scenemanager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(Scene* scene)
{
	scenes.push_back(scene);
}

//there's probably a more dynamic way to handle this but i'm sleep deprived so w/e

void SceneManager::RemoveScene(int sceneIndex) 
{
	//scenes[previousSceneIndex]->isLoaded = false;
	scenes[sceneIndex]->isLoaded = false;

	//scenes.begin()
	//scenes.erase(sceneIndex);
}

void SceneManager::LoadScene(int sceneIndex, sf::RenderWindow& window)
{
	//RemoveScene();
	//scenes[currentSceneIndex]->isLoaded = false;
	//previousSceneIndex = currentSceneIndex;

	currentSceneIndex = sceneIndex;

	if (!scenes[currentSceneIndex]->isLoaded)
	{
		std::cout << "loaded scene index: " << currentSceneIndex << std::endl;
		scenes[currentSceneIndex]->Load(window);
	}
}

void SceneManager::UpdateScene(sf::RenderWindow& window)
{
	if (scenes.size() > 0)
	{
		scenes[currentSceneIndex]->Update(window);
	}
}

void SceneManager::RenderScene(sf::RenderWindow& window)
{
	if (scenes.size() > 0)
	{
		scenes[currentSceneIndex]->Render(window);
	}
}

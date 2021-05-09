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

void SceneManager::RemoveScene(int sceneIndex)
{
	//scenes.begin()
	//scenes.erase(sceneIndex);
}

void SceneManager::LoadScene(int sceneIndex, sf::RenderWindow& window)
{
	//scenes[currentSceneIndex]->isLoaded = false;
	currentSceneIndex = sceneIndex;
	if (!scenes[currentSceneIndex]->isLoaded)
	{
		std::cout << "loaded scene index: " << currentSceneIndex << std::endl;
		scenes[currentSceneIndex]->Load(window);
	}
}

void SceneManager::UpdateScene()
{
	if (scenes.size() > 0)
	{
		scenes[currentSceneIndex]->Update();
	}
}

void SceneManager::RenderScene(sf::RenderWindow& window)
{
	if (scenes.size() > 0)
	{
		scenes[currentSceneIndex]->Render(window);
	}
}

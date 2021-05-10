#include "leveltwo.h"
#include "example.h"
#include "gameload.h"

LevelTwo::LevelTwo()
{
	Index = 2;
}

LevelTwo::~LevelTwo()
{
}

void LevelTwo::Load(sf::RenderWindow& window)
{
	Scene::Load(window);

	backgroundSprite = kage::TextureManager::getSprite("data/breakout/newpixelnightsky.png");
	sf::Vector2u resolution = backgroundSprite->getTexture()->getSize();
	backgroundSprite->setScale(float(window.getSize().x) / resolution.x, float(window.getSize().y) / resolution.y);


	Example::gameMapTiles.LoadTileTextures();
	GameLoad::LoadMap(MapFileTwo, Example::gameMapTiles.saveMap, Example::gameMapTiles);

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		Example::gameMapTiles.tiles[i].SetSpriteCycle(sf::Vector2i(0, 1), sf::Vector2i(6, 1), 200);
	}

}

void LevelTwo::Update(sf::RenderWindow& window)
{
	ImGui::Begin("This is level two :D");
	if (ImGui::Button("Level 1"))
	{
		Example::sManager.RemoveScene(Index);
		Example::sManager.LoadScene(1, window);
		//m_running = false;
	}
	if (ImGui::Button("Return to main menu"))
	{
		Example::sManager.RemoveScene(Index);
		Example::sManager.LoadScene(0, window);
		//m_running = false;
	}
	ImGui::End();

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		Example::gameMapTiles.tiles[i].Update();
	}

	Scene::Update(window);
}

void LevelTwo::Render(sf::RenderWindow& window)
{
	window.draw(*backgroundSprite);

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		Example::gameMapTiles.tiles[i].Render(window);
	}

	Scene::Render(window);
}


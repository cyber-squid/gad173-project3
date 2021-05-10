#include "levelone.h"
#include "example.h"
#include "gameload.h"


LevelOne::LevelOne()
{
	Index = 1;
}

LevelOne::~LevelOne()
{
}

void LevelOne::Load(sf::RenderWindow& window)
{
	Scene::Load(window);
	//isLoaded = true;

	//std::cout << "cookies" << std::endl;

	backgroundSprite = kage::TextureManager::getSprite("data/breakout/newpixelkoipond.jpg");
	sf::Vector2u resolution = backgroundSprite->getTexture()->getSize();
	backgroundSprite->setScale(float(window.getSize().x) / resolution.x, float(window.getSize().y) / resolution.y);


	Example::gameMapTiles.LoadTileTextures();
	GameLoad::LoadMap(MapFileOne, Example::gameMapTiles.saveMap, Example::gameMapTiles);

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		Example::gameMapTiles.tiles[i].SetSpriteCycle(sf::Vector2i(0, 1), sf::Vector2i(6, 1), 200);
	}
	//std::cout << "a mahusive bescet" << std::endl;
	//isLoaded = false;
}

void LevelOne::Update(sf::RenderWindow& window)
{
	ImGui::Begin("This is level one :)");
	if (ImGui::Button("Level 2"))
	{
		Example::sManager.RemoveScene(Index);
		Example::sManager.LoadScene(2, window);
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
	//std::cout << "some flavour text for you" << std::endl;
}

void LevelOne::Render(sf::RenderWindow& window)
{
	window.draw(*backgroundSprite);

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		Example::gameMapTiles.tiles[i].Render(window);
	}

	Scene::Render(window);
}


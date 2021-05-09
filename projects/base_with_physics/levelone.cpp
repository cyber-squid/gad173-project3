#include "levelone.h"
#include "app.h"

LevelOne::LevelOne()
{
}

LevelOne::~LevelOne()
{
}

void LevelOne::Load(sf::RenderWindow& window)
{
	Scene::Load(window);
	//isLoaded = true;

	std::cout << "cookies" << std::endl;

	backgroundSprite = kage::TextureManager::getSprite("data/breakout/newpixelkoipond.jpg");
	sf::Vector2u resolution = backgroundSprite->getTexture()->getSize();
	backgroundSprite->setScale(float(window.getSize().x) / resolution.x, float(window.getSize().y) / resolution.y);


	std::cout << "a mahusive bescet" << std::endl;
	//isLoaded = false;
}

void LevelOne::Update()
{
	ImGui::Begin("Kage2D");
	if (ImGui::Button("More test"))
	{
		//m_running = false;
	}
	ImGui::End();
	Scene::Update();
	//std::cout << "some flavour text for you" << std::endl;
}

void LevelOne::Render(sf::RenderWindow& window)
{
	window.draw(*backgroundSprite);
	Scene::Render(window);
}


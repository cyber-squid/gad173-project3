#include "mainmenu.h"
#include "app.h"
#include "example.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Load(sf::RenderWindow& window)
{
	Scene::Load(window);

	std::cout << "penguin" << std::endl;

	backgroundSprite = kage::TextureManager::getSprite("data/breakout/newpixelmountainvillage.jpg");
	sf::Vector2u resolution = backgroundSprite->getTexture()->getSize();
	backgroundSprite->setScale(float(window.getSize().x) / resolution.x, float(window.getSize().y) / resolution.y);

	StartButtonTexture = kage::TextureManager::getTexture("placeholder.png");
	StartButton.setTexture(*StartButtonTexture);

	std::cout << "a wee penglewengle" << std::endl;
	//isLoaded = false;
}

void MainMenu::Update()
{
	ImGui::Begin("Welcome to the Main Menu!");
	if (ImGui::Button("Test"))
	{
		//m_running = false;
	}
	if (ImGui::ImageButton(StartButton))
	{
		//SceneManager::scenes[1]->isLoaded = false;
		//sManager.LoadScene(0, m_window);
	}
	ImGui::End();

	Scene::Update();
	//std::cout << "hi there" << std::endl;
}

void MainMenu::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
	window.draw(*backgroundSprite);
	//std::cout << "whaddup" << std::endl;
}


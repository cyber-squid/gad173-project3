#include "mainmenu.h"
#include "example.h"

MainMenu::MainMenu()
{
	Index = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::Load(sf::RenderWindow& window)
{
	Scene::Load(window);

	//std::cout << "penguin" << std::endl;

	backgroundSprite = kage::TextureManager::getSprite("data/breakout/newpixelmountainvillage.jpg");
	sf::Vector2u resolution = backgroundSprite->getTexture()->getSize();
	backgroundSprite->setScale(float(window.getSize().x) / resolution.x, float(window.getSize().y) / resolution.y);

	//StartButtonTexture = kage::TextureManager::getTexture("placeholder.png");
	//StartButton.setTexture(*StartButtonTexture);

	//std::cout << "a wee penglewengle" << std::endl;
	//isLoaded = false;
}

void MainMenu::Update(sf::RenderWindow& window)
{
	ImGui::Begin("Welcome to the Main Menu!");
	if (ImGui::Button("Test"))
	{
		//m_running = false;
	}
	if (ImGui::Button("Level 1"))
	{
		//Example::sManager.scenes[Index]->isLoaded = false;
		Example::sManager.RemoveScene(Index);
		Example::sManager.LoadScene(1, window);
	}
	if (ImGui::Button("Level 2"))
	{
		//Example::sManager.scenes[Index]->isLoaded = false;
		Example::sManager.RemoveScene(Index);
		Example::sManager.LoadScene(2, window);
	}
	ImGui::End();

	/*ImGui::Begin("Trying another menu item");
	if (ImGui::Button("penguin"))
	{
		//m_running = false;
	}
	if (ImGui::ImageButton(StartButton))
	{
		//Example::sManager.scenes[1]->isLoaded = false;
		//sManager.LoadScene(0, m_window);
	}
	ImGui::End();*/
	//std::cout << "hi there" << std::endl;


	Scene::Update(window);

}

void MainMenu::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
	window.draw(*backgroundSprite);
	//std::cout << "wassup" << std::endl;
}


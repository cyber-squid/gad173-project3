#include "example.h"
#include "mainmenu.h"
#include "levelone.h"
#include "leveltwo.h"

SceneManager Example::sManager = SceneManager();
GameMap Example::gameMapTiles = GameMap();

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{

	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	sManager.AddScene(new MainMenu());
	sManager.AddScene(new LevelOne());
	sManager.AddScene(new LevelTwo());

	sManager.LoadScene(0, m_window);

	return true;
}

void Example::update(float deltaT)
{
	// You need to update the physics system every game update

	//kage::Physics::update(deltaT);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();

	sManager.UpdateScene(m_window);

}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	// The next line draws the physics debug info. This should be removed in a final release.
	//kage::Physics::debugDraw(&m_window, 64);

	sManager.RenderScene(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}


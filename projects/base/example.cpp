#include "example.h"
#include "grid.h"
#include "map.h"
#include "saveandload.h"

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

void Example::setBackground(std::string textureFilename)
{
	m_backgroundSprite = kage::TextureManager::getSprite(textureFilename);
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
}

bool Example::start()
{
	//Tiles MapTiles;
	//testTexture = kage::TextureManager::getTexture("data/breakout/farhantilesheet.png");
	setBackground("data/breakout/newpixelkoipond.jpg");

	MapTiles.PrintCurrentSave();
	
	//exampleTileAnim.Load(testTexture, 60, 40);
	//exampleTileAnim.SetSpriteCycle(sf::Vector2i(0, 2), sf::Vector2i(6, 2), 70);
	//exampleTileAnim.spritesheet.setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y));

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		MapTiles.tiles[i].SetSpriteCycle(sf::Vector2i(0, 1), sf::Vector2i(6, 1), 200);
	}

	return true;
}

void Example::update(float deltaT)
{	
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	
	
	ImGui::Begin("Options"); 
	if (ImGui::Button("SAVE Slot 1"))
	{
		setBackground("data/breakout/newpixelkoipond.jpg");
		SaveAndLoad::SaveMap(mapOneSavefileName, MapTiles.saveMap);
	}
	if (ImGui::Button("LOAD Slot 1"))
	{
		setBackground("data/breakout/newpixelkoipond.jpg");
		SaveAndLoad::LoadMap(mapOneSavefileName, MapTiles.saveMap, MapTiles);
	}
	if (ImGui::Button("SAVE Slot 2"))
	{
		setBackground("data/breakout/newpixelmountainvillage.jpg");
		SaveAndLoad::SaveMap(mapTwoSavefileName, MapTiles.saveMap);
	}
	if (ImGui::Button("LOAD Slot 2"))
	{
		setBackground("data/breakout/newpixelmountainvillage.jpg");
		SaveAndLoad::LoadMap(mapTwoSavefileName, MapTiles.saveMap, MapTiles);
	}
	if (ImGui::Button("Eraser"))
	{
		tileIDSelected = 0;
	}
	if (ImGui::ImageButton(*MapTiles.redBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 1;
	}
	if (ImGui::ImageButton(*MapTiles.blueBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 2;
	}
	if (ImGui::ImageButton(*MapTiles.greenBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 3;
	}
	if (ImGui::ImageButton(*MapTiles.yellowBlockTexture, sf::Vector2f(53, 25)))
	{
		tileIDSelected = 4;
	}
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();


	//how it should work:
	//-if mouse clicked, get x and y
	//-divide x and y by width and height
	//-cast them to ints to keep accuracy, then use the formula x + y * x cell count
	//-use this to determine index number for the grid tile and load the selected sprite
	//to the corresponding index no.  depending on which tile type the player selected
	

	//MapTiles.GetMousePosOnGrid(m_window);
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window); 
	
	if (
		mousePos.x >= GRID_OFFSET_X && mousePos.x <= X_LINE_LENGTH 
			&& mousePos.y >= GRID_OFFSET_Y && mousePos.y <= (Y_LINE_LENGTH+ (CELL_HEIGHT / 2))
				&& sf::Mouse::isButtonPressed(sf::Mouse::Left) )
	{
	
		int mouseCellX = ((mousePos.x - GRID_OFFSET_X) / CELL_WIDTH); 
		int mouseCellY = ((mousePos.y - GRID_OFFSET_Y) / CELL_HEIGHT);

		int selectedSquare = mouseCellX + mouseCellY  * (X_LINES_AMNT - 1);
		std::cout << selectedSquare << std::endl;
		
		if (tileIDSelected == 0)
		{
			MapTiles.tiles[selectedSquare].Load(MapTiles.blueBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
			MapTiles.tiles[selectedSquare].spritesheet.setColor(sf::Color(255, 255, 255, 0));
			
			MapTiles.tiles[selectedSquare].tileID = 0;
			MapTiles.saveMap[selectedSquare] = 0;
		}
		if (tileIDSelected == 1)
		{
			MapTiles.tiles[selectedSquare].Load(MapTiles.redBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
			MapTiles.tiles[selectedSquare].spritesheet.setColor(sf::Color(255, 255, 255, 255));
			
			MapTiles.tiles[selectedSquare].tileID = 1;
			MapTiles.saveMap[selectedSquare] = 1;
		}
		if (tileIDSelected == 2)
		{
			MapTiles.tiles[selectedSquare].Load(MapTiles.blueBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
			MapTiles.tiles[selectedSquare].spritesheet.setColor(sf::Color(255, 255, 255, 255));
			
			MapTiles.tiles[selectedSquare].tileID = 2;
			MapTiles.saveMap[selectedSquare] = 2;
		}
		if (tileIDSelected == 3)
		{
			MapTiles.tiles[selectedSquare].Load(MapTiles.greenBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
			MapTiles.tiles[selectedSquare].spritesheet.setColor(sf::Color(255, 255, 255, 255));
			
			MapTiles.tiles[selectedSquare].tileID = 3;
			MapTiles.saveMap[selectedSquare] = 3;
		}
		if (tileIDSelected == 4)
		{
			MapTiles.tiles[selectedSquare].Load(MapTiles.yellowBlockTilesheet, TILE_WIDTH, TILE_HEIGHT);
			MapTiles.tiles[selectedSquare].spritesheet.setColor(sf::Color(255, 255, 255, 255));
			
			MapTiles.tiles[selectedSquare].tileID = 4;
			MapTiles.saveMap[selectedSquare] = 4;
		}
	}

	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		MapTiles.tiles[i].Update();
	}
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	m_window.draw(LineGrid.GridBackground);
	
	for (size_t i = 0; i < TILE_ARRAY_SIZE; i++)
	{
		//m_window.draw(MapTiles.tileset[i]);
		MapTiles.tiles[i].Render(m_window);
	}

	LineGrid.Draw(m_window);

}

void Example::cleanup()
{
	delete m_backgroundSprite;
}


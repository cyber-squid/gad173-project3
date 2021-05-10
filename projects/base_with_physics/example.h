#pragma once

#include "app.h"
#include "scenemanager.h"
#include "scene.h"
#include "gamemap.h"


class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();


	static SceneManager sManager;

	static GameMap gameMapTiles;

	sf::Sprite *m_backgroundSprite;
};

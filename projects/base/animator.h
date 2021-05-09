#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// Allows for looped animations of a given spritesheet with horizontal frames. 
/// This takes a sprite, loads the parameters set for its texture and which parts of the texture to display, 
/// and updates each frame according to the speed, start and end of the animation.
/// </summary>
class Animator
{
public:
	Animator();
	~Animator();

	//sf::Vector2i currentFrame;
	sf::Vector2i startFrames;
	sf::Vector2i endFrames;
	int cycleSpeed = 0;

	void Load(sf::Texture *tileSheet, int spriteWidth, int spriteHeight);
	void Update();
	void Render(sf::RenderWindow& window);
	void SetSpriteCycle(sf::Vector2i startFrames, sf::Vector2i endFrames, int speed);

	sf::Sprite spritesheet;

protected:

	int spriteWidth = 0;
	int spriteHeight = 0;

	int xIndex = 0;
	int yIndex = 0;

	sf::Clock clock;

};
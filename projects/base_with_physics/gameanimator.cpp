#include "gameanimator.h"

GameAnimator::GameAnimator()
{
}

GameAnimator::~GameAnimator()
{
}

// sets the object's sprite to the texture given, then sets the part of the texture displayed with the
// pixel size of the sprite given. This should be the size of a single image on the texture sheet.
void GameAnimator::Load(sf::Texture* tileSheet, int spriteWidth, int spriteHeight)
{
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;

	spritesheet.setTexture(*tileSheet);
	spritesheet.setTextureRect(sf::IntRect(spriteWidth * xIndex,
		spriteHeight * yIndex, spriteWidth, spriteHeight));
	//spritesheet.setScale(spriteSize);
}

void GameAnimator::Update()
{
	sf::Time countdown = clock.getElapsedTime();
	//sf::FloatRect test;
	//currentFrame = sf::Vector2i(xIndex, yIndex);

	if (countdown.asMilliseconds() > cycleSpeed)
	{

		int x = spriteWidth * xIndex;
		int y = spriteHeight * yIndex;

		spritesheet.setTextureRect(sf::IntRect(x, y, spriteWidth, spriteHeight));

		xIndex++;

		if (xIndex > endFrames.x)
		{
			xIndex = startFrames.x;

			if (yIndex < 1)
			{
				//spritesheet.setColor(sf::Color(255, 255, 255, 0));
			}
		}
		if (yIndex > endFrames.y)
		{
			yIndex = startFrames.y;
		}

		clock.restart();
	}
}

void GameAnimator::Render(sf::RenderWindow& window)
{
	window.draw(spritesheet);
}

void GameAnimator::SetSpriteCycle(sf::Vector2i startFrames, sf::Vector2i endFrames, int speed)
{
	this->startFrames = startFrames;
	this->endFrames = endFrames;
	cycleSpeed = speed;

	//currentFrame = startFrames;

	xIndex = startFrames.x;
	yIndex = startFrames.y;
}
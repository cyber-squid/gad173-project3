#pragma once
#include <SFML/Graphics.hpp>
#include "animator.h"

/// <summary>
/// This is used in the map class to create an array of animators for the "tile" sprites used in that class.
/// Also contains an int to mark which type of tile it is, and what texture should be printed according to it.
/// </summary>
class Tile : public Animator
{
public:

	Tile();
	~Tile();

	int tileID;

};
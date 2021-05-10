#pragma once
#include <iostream>
#include "gamemap.h"

//using namespace std;

class GameLoad
{

	GameLoad();
	~GameLoad();

public:

	// static void SaveMap(std::string FileName, int* mapArray);
	static void LoadMap(std::string FileName, int* mapArray, GameMap& map);
};
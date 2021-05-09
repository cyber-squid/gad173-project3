#pragma once
#include <iostream>
#include "map.h"

//using namespace std;

class SaveAndLoad
{
	
	SaveAndLoad();
	~SaveAndLoad();

public:

	static void SaveMap(std::string FileName, int* mapArray);
	static void LoadMap(std::string FileName, int* mapArray, Map& map);
};
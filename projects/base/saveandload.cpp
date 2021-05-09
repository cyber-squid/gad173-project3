#include <fstream>
#include <string>
#include "saveandload.h"
#include "grid.h"

using namespace std;

SaveAndLoad::SaveAndLoad()
{
}

SaveAndLoad::~SaveAndLoad()
{
}


void SaveAndLoad::SaveMap(std::string FileName, int* mapArray)
{
	ofstream MapLayoutFile;
	MapLayoutFile.open(FileName);

	for (size_t y = 0; y < CELL_COUNT_Y; y++)
	{
		for (size_t x = 0; x < CELL_COUNT_X; x++)
		{
			int i = x + y * CELL_COUNT_X;
			MapLayoutFile << mapArray[i] << " / ";
		}
		MapLayoutFile << "\n";
	}

	MapLayoutFile.close();
}

void SaveAndLoad::LoadMap(string FileName, int* mapArray, Map& map)
{
	string mapDatastream;
	ifstream MapLayoutFile(FileName);

	if (MapLayoutFile.is_open())
	{
		int slashIndex = -1;
		int i = 0;

		while (std::getline(MapLayoutFile, mapDatastream))
		{
			while (true)
			{
				int cutStart = slashIndex + 1;
				slashIndex = mapDatastream.find('/', slashIndex + 1);
				string numStrCut = mapDatastream.substr(cutStart, slashIndex - cutStart);

				if (slashIndex == -1)
					break;

				int numStrResult = stoi(numStrCut);
				mapArray[i] = numStrResult;
				i++;
			}
		}
	}
	else
	{
		std::cout << "Whoops! could not open file." << std::endl;
	}

	map.PrintCurrentSave();
}

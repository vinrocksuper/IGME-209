#include "gameLevel.h"
#include <iostream>;
using namespace std;
gameLevel::gameLevel()
{
	std::cout << "gameLevel created" << endl;
	levelNum = 1;
	levelName = nullptr;
	map = nullptr;
	
}

gameLevel::~gameLevel()
{
	cout << "gamelevel deleted" << endl;
	delete levelName;
	delete map;
}

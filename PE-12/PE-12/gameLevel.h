#pragma once
#include <string>

class gameLevel
{
public:
	gameLevel();
	~gameLevel();

private:
	int levelNum;
	char* levelName;
	int** map;
};


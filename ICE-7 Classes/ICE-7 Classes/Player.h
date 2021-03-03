#pragma once

class Player
{
public:
	Player(char* name, int s, int v, int d);
	Player();

	void printPlayer();

private:
	char* name;
	int str;
	int vit;
	int dex;
};

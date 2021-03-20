#pragma once
#include "Player.h"
class Fighter :
    public Player
{

public:
	Fighter(char* name, int s, int v, int d, char* sk) :Player(name, s, v, d)
	{
		skill = sk;
	}
	Fighter();
	~Fighter();
	void PrintFighter();
	void attack(Player* otherP) override;
private:
	char* skill;
	



	
};


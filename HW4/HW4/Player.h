#pragma once

class Player
{
public:
	Player(char* name, int s, int v, int d);
	Player();
	~Player();
	void printPlayer();


	char* getName() const
	{
		return name;
	}

	virtual void attack(Player* otherP);

private:
	char* name;
	int str;
	int vit;
	int dex;
};

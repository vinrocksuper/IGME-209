#include "Player.h"
#include <iostream>
using namespace std;
	Player::Player()
	{
		name = (char*)"Unknown";
		str = 10;
		dex = 10;
		vit = 10;
	}
Player::Player(char* name, int s, int v, int d)
{
	Player::name = name;
	str = s;
	vit = v;
	dex = d;
}

void Player::printPlayer()
{
	std::cout << name << endl;
	cout << "Has a strength of " << str << endl;
	cout << "Has a dexterity of " << dex << endl;
	cout << "Has a vitality of " << vit << endl;

}


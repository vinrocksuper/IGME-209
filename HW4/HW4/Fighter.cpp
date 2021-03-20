#include "Fighter.h"
using namespace std;
#include <iostream>;

Fighter::Fighter()
{
	skill = (char*)"headbutt";
}


Fighter::~Fighter()
{
	cout << "Destroying Fighter Object" << endl;
}


void Fighter::attack(Player* otherP)
{
	cout << getName() << " attacks " << otherP->getName() << " with a weapon!" << endl;
}

void Fighter::PrintFighter()
{
	Player::printPlayer();
	cout <<  "skill is " << skill<<endl;
}

// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Player.h";
#include "Fighter.h";

int main()
{
	cout << "Welcome one and all to the HW4 Battle Royale! 10 Players, enter, 1 Player leaves! (well really 0, but you get the jist)" << endl;
	Player* battlers[10];
	char* names[] = { (char*)"Bob", (char*)"Tim",(char*)"Tom",(char*)"John" ,(char*)"Dave" ,(char*)"Alice" ,(char*)"Amy" ,(char*)"Chloe" ,(char*)"Sue" ,(char*)"Mary" };
	int flip;
	int survivors = 10;
	for(int i=0 ; i<10 ;i++)
	{
		flip = rand() % 2;
		if(flip == 0)
		{
			battlers[i] = new Player(names[i], 11, 12, 13);
		}else
		{
			battlers[i] = new Fighter(names[i], 11, 12, 13, (char*)"Bludgeon");
		}
	}

	while(survivors > 1)
	{
		for (Player* battler : battlers)
		{
			if (battler == nullptr)
			{
				continue;
			}
			flip = rand() % 10;
			while (battlers[flip] == nullptr || battlers[flip] == battler)
			{
				flip = rand() % 10;
			}
			battler->attack(battlers[flip]);
			battlers[flip] = nullptr;
			survivors--;
		}
	}
	for (Player* battler : battlers)
	{
		if(battler == nullptr)
		{
			continue;
		}
		cout << battler->getName() << " is the winner of this tournament!" << endl;
	}


	for (auto& battler : battlers)
	{
		delete battler;
	}

	
	/**
	 *
	 *
	 *	Player player1 = Player();
	Player player2 = Player((char*)"Bob", 11, 12, 13);
	Player* player3 = new Player();
	Player* player4 = new Player((char*)"Alice", 14, 15, 16);

	Fighter fighter1 = Fighter();
	Fighter fighter2 = Fighter((char*)"David", 17, 18, 19, (char*)"Smite");
	

	
	player1.printPlayer();
	player2.printPlayer();
	player3->printPlayer();
	player4->printPlayer();
	fighter1.PrintFighter();
	fighter2.PrintFighter();
	delete player3;
	delete player4;
	 *
	 *
	 * 
	 */



}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

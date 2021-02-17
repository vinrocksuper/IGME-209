// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster(); // With MoveableObject there is usually 1 less bit used compared to Monster/Player
	MovableObject *pOne = new Player();  // Both increment the 2nd bit by 2
	Monster *fakeMonster = (Monster*)pOne; 

	// add code here
	cout << &boss <<endl;
	cout << &pOne << endl;
	cout << &fakeMonster << endl; 

	boss->xPos = 32;
	boss->yPos = 11;
	pOne->xPos = 53; // pOne's set pos doesn't matter since pOne's positions are overwritten by fakeMonster's set
	pOne->yPos = 38; // since they point to the same target and are edited in joint.
	fakeMonster->xPos = 9;
	fakeMonster->yPos = 77;

	boss->PrintPos(); // prints X: 32 Y: 11
	pOne->PrintPos(); // prints X: 9 Y: 77
	fakeMonster->PrintPos(); // prints X: 9 Y: 77


	delete boss;
	//delete pOne; commented out to prevent second deletion
	delete fakeMonster; // Fake monster was attempting to delete a deleted pointer

	_getch();
    return 0;
}


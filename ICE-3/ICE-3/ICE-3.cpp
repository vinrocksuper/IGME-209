// ICE-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"; // Will print now after including the header in the .h
using namespace std;

int main()
{
   printName();
}



// Will compile wont run though bc it's after main()
void printName() {
    cout << "Vincent Li" << endl;
}



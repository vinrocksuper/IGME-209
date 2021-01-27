// ICE-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int seconds = 31 * 24 * 60 * 60; // 31 days in Dec * 24hr/day * 60mins/hr * 60sec/min
    double circleArea = 3.1415926 * 6.2 * 6.2;
    int divisionTest = 3 / 5;
    std::cout << "There are " << seconds << " seconds in December" << std::endl;
    std::cout << "A circle with 6.2 radius has an area of "<< circleArea << std::endl;
    std::cout << "Integer Division Test: 3/5 results in: " << divisionTest << std::endl; // Looks like truncates in integer division
    std::cout << "Integer Division Test: 6/5 results in: " << 6 / 5 << std::endl; // Test case Cont.
    std::cout << "Integer Division Test: 7/2 results in: " << 7 / 2 << std::endl; // Test case Cont.
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

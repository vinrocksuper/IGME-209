// PE-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
using namespace std;
int iteration(int seats)
{
	int total = 0;
	for(int i=0;i<seats;i++)
	{
		if(i%2 == 0)
		{
			total += 4;
		}else
		{
			total += 3;
		}
	}
	return total;
}
int recursion(int seats , int total)
{
	if(seats%2==0)
	{
		total += 4;
	}else
	{
		total += 3;
	}
	if(seats > 1)
	{
		return recursion(--seats,total);
	}
	return total;
}
int formula(int seats)
{
	if(seats%2 == 0)
	{
		return 3.5*seats;
	}
	return ((seats-1)*3.5)+3;
}

int main()
{



	cout << "Testing @ N = 10" << endl;
	
	chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	cout << "Iteration " << iteration(10) << endl;
	chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::steady_clock::now();
	cout << "Recursion " << recursion(10, 0) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::steady_clock::now();
	cout << "Formula " << formula(10) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	cout << endl;

	cout << "Testing @ N = 100" << endl;
	begin = chrono::steady_clock::now();
	cout << "Iteration " << iteration(100) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::steady_clock::now();
	cout << "Recursion " << recursion(100, 0) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::steady_clock::now();
	cout << "Formula " << formula(100) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;


	cout << endl;

	cout << "Testing @ N = 1000" << endl;
	begin = chrono::steady_clock::now();
	cout << "Iteration " << iteration(1000) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::steady_clock::now();
	cout << "Recursion " << recursion(1000, 0) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::steady_clock::now();
	cout << "Formula " << formula(1000) << endl;
	end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;


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

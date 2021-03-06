// Brandon Jones
//	COP2000.001
// Takes input from averageTemp file and returns the num
// of above, below, and average temperature days. 

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std; 

class Average
{
private:
	int averageArray[3];   //Array for above, below, and average temps
	int tempArray[30];     //Array for all temps from input file
	int average; 
	int setAverage(int a[]);   //Takes temp array and finds average temp

	//loops through array to find num of above, below and average temps
	int findNumOfAverage();    
	int findNumOfAboveAverage(); 
	int findNumOfBelowAverage();
	
	//displays output
	void display();
	 
public:
	Average();
	void readInput(string);
	void driver(); 
};

//sets all values in averageArray to 0
Average::Average()
{
	cout << endl << "The number of above, below, and average temperature days" << endl;
	averageArray[0] = 0;
	averageArray[1] = 0;
	averageArray[2] = 0;
}

void Average::display()
{
	int a; 
	int b; 
	int c; 
	
	//sets the num of above, below, and average days into variables
	a = findNumOfAboveAverage();
	b = findNumOfBelowAverage(); 
	c = findNumOfAverage();


	//display the value
	cout << endl << endl; 
	cout << "Number of above average days: " << a << endl; 
	cout << "Number of below average days: " << b << endl;
	cout << "Number of average days:       " << c << endl;
}

//takes input from external file
void Average::readInput(string s)
{
	ifstream file(s);
	if (file.is_open())
	{
		for (int i = 0; i < 30; i++)
		{
			file >> tempArray[i]; 
		}
	}
	if (!file)
	{
		cout << "Input file did not open" << endl << endl;
	}
}

//takes in an array of int and finds average number 
int Average::setAverage(int a[])
{
	int sum = 0;
	
	for (int i = 0; i < 30; i++)
	{
		sum = sum + a[i];
	}
	average = sum / 30; 

	return average; 
}

//driver function
void Average::driver()
{
	readInput("NovTemps.txt");
	display();
}

//finds num of average days and stores into seperate array
int Average::findNumOfAverage()
{
	int a; 
	int numOfAvg = 0; 

	a = setAverage(tempArray);

	for (int i = 0; i < 30; i++)
	{
		if (tempArray[i] == a)
		{
			numOfAvg++;
		}
	} 
	averageArray[2] = numOfAvg; 

	return averageArray[2]; 
}

//finds num of above average days and stores into seperate array
int Average::findNumOfAboveAverage()
{
	int a;
	int numOfAboveAvg = 0;

	a = setAverage(tempArray);

	for (int i = 0; i < 30; i++)
	{
		if (tempArray[i] > a)
		{
			numOfAboveAvg++;
		}
	}
	averageArray[0] = numOfAboveAvg;

	return averageArray[0];
}

//finds num of below average days and stores into seperate array
int Average::findNumOfBelowAverage()
{
	int a;
	int numOfBelowAvg = 0;

	a = setAverage(tempArray);

	for (int i = 0; i < 30; i++)
	{
		if (tempArray[i] < a)
		{
			numOfBelowAvg++;
		}
	}
	averageArray[1] = numOfBelowAvg;

	return averageArray[1];
}

//main function
int main()
{
	Average average; 
	average.driver(); 

	return 0; 
}


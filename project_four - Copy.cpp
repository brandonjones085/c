// Brandon Jones
//
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	//variables
	int inputNum;
	int sum = 0;
	int storeNum = 1;
	int asterisk;
	int i;
	int j;


	ifstream inputFile;

	inputFile.open("sales.txt");

	if (!inputFile) {
		cout << "Input file did not open" << endl << endl;
		return 10;
	}

	cout << "Today's Sales Chart" << endl << endl;
	cout << "Gather input from file... " << endl << endl;
	cout << "Daily Sales (each* = $1000)" << endl;

	while (inputFile >> inputNum) {
		asterisk = inputNum / 1000;
		cout << endl;
		cout << "Store " << storeNum << " ";

		for (i = 0; i <= asterisk - 1; i++) {
			cout << "*";

		}

		storeNum++;

	}

	cout << endl;

	return 0;
}


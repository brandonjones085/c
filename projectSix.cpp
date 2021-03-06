
#include "pch.h"
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std; 

class Game
{
private: 
	int balance; 
	int rolledValue; 
	char holdValue;

	void validateBalance(int&); 
	void validateAgain(char&); 

public: 
	
	void setBalance(); 
	void roll(); 
	void display(); 
	void again(); 
	Game();
};

Game::Game() {
	cout << "Rock Your World!\n" << endl; 
	balance = 0; 
	srand(time(NULL));
	
}

void Game::validateBalance(int& i) {
	while (!cin || i < 1) {
		cin.clear();
		cin.sync();
		cin.ignore(); 
		cout << "\nInvalid amount entered, try again: ";
		cin >> i; 
	}
}

void Game::roll() {
	rolledValue = rand() % 6 + 1;
	cout << "\nRolling...\n" << endl; 
	
}

void Game::display() {
	
	if (rolledValue % 2 == 0) {
		cout << "Even rolled, you win $1" << endl; 
		balance += 1; 
		cout << "Balance = $" << balance << endl; 
	}
	else {
		cout << "Odd rolled, you lose $1" << endl; 
		balance -= 1; 
		cout << "Balance = $" << balance << endl; 
		if (balance < 1) {
			 
			cout << "\n\nGame over. Ending Balance = $0" << endl; 
			cout << "Thanks for playing" << endl; 
			exit(0);
		}
	}
}


void Game::setBalance() {
	cout << "Enter starting balance (minimum of $1): "; 
	cin >> balance; 
	validateBalance(balance); 
	cout << "Starting balance = $" << balance << endl << endl;
}

void Game::validateAgain(char& i) {
	i = tolower(i); 
	while (i != 'y' && i !='n') {
		cout << "Invalid input! Try again: "; 
		cin >> i; 
		i = tolower(i); 
	}
}

void Game::again() {
	cout << "\nWould you like to roll again (y=yes, n=no): "; 
	cin >> holdValue; 
	validateAgain(holdValue); 
	while (holdValue == 'y') {
		roll(); 
		display(); 
		again(); 
		cin.ignore(); 
	}
	cout << "Thanks for playing!" << endl; 
}


int main()
{
	Game start; 
	

	start.setBalance(); 
	start.roll(); 
	start.display(); 
	start.again(); 
	
	return 0; 
}






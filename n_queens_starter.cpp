/********************************************************
 * Finds all solutions to N Queens
 *********************************************************/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

void menu();
void outputBoard(vector<int>, int);

int main() {
	int size = 8; // start up default to standard checker board size
	
// The following 7 lines of code are to test the outputBoard()
// You may choose to comment out in your submitted n_queens.cpp
	vector<int> queen8 = { 0, 4, 7, 5, 2, 6, 1, 3};
	vector<int> queen14 = {0, 2, 4, 6, 11, 9, 12, 3, 13, 8, 1, 5, 7, 10};
	cout << "One possible 8-Queens solution:\n";
	outputBoard(queen8, size);
	cout << "\nOne possible 14-Queens solution:\n";
	size = 14;
	outputBoard(queen14, size);

// end of outputBoard() test
	
	string choice;
	while(true)
	{
		menu();
		cin >> choice;
		
		switch (choice[0]) {
			case 's': // change size
			case 'S':
				cout << "Enter Size of checker board: ";
				cin >> size;
				cin.ignore(1000, 10);
				
				if (size != 1 && size < 4) {
					cout << "SIZE OF BOARD MUST BE 1 OR GREATER THAN OR EQUAL TO 4\n\n";
					break;
				}
				break;	
				
			case 'd': // display all solutions
			case 'D':
				cout << "\n...........   SOLUTIONS   ...........\n\n";
				break;		
				
			case 'u': // display only the unique solutions
			case 'U':
				cout << "\n...........UNIQUE SOLUTIONS...........\n\n";
				break;		
				
			case 'q':
			case 'Q':
				return 0;
				break;
				
		    default:
				cout << "Invalid Entry\n";
				break;
		}
	}
	return 0;
}

void menu()
{
	cout << "==== N-Queen Test Menu ===="
		 << "\n\tS-Checker Board Size"
		 << "\n\tD-Display solutions"
		 << "\n\tU-Display Unique solutions"
		 << "\n\tQ-Quit"
		 << "\n\tEnter your Choice: ";

}
 
/*
 * precondition: input the n-queens\' solution array and its size
 * postcondition: output the checker board 
 */
void outputBoard(vector<int> ar, int size) {
	int i, j;
	cout << "*|" ;
	for(i=0; i<size; i++) 
		cout << (i%10) << "|";
	cout << "*\n";
	for(i=0; i<size; i++) {
		cout << (i%10) << "|";
		for(j=0; j<size; j++)
			if(j == ar[i])
				cout << "X" << "|";
			else
				cout << "_|";
		cout << (i%10) << endl;
	}
	cout << "*|";
	for(i=0; i<size; i++) 
		cout << (i%10) << "|";
	cout << "*\n\n";
}


/********************************************************
 * Name:Jun Tan
 * Description: Finds all solutions to N Queens
 *********************************************************/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int size;
vector<int> queen;

void menu();
void outputBoard(vector<int>, int);
void displyCheckerBoard(int);
void solveQueen(int);
bool canPlace(int, int);
void initialize();

int main() {
  size = 8; // start up default to standard checker board size

// The following 7 lines of code are to test the outputBoard()
// You may choose to comment out in your submitted n_queens.cpp
  vector<int> queen8 = { 0, 4, 7, 5, 2, 6, 1, 3};
  vector<int> queen14 = {0, 2, 4, 6, 11, 9, 12, 3, 13, 8, 1, 5, 7, 10};
  cout << "One possible 8-Queens solution:\n";
  outputBoard(queen8, size);
  cout << "\nOne possible 14-Queens solution:\n";
  size = 14;
  outputBoard(queen14, size);

  initialize();
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
		displyCheckerBoard(size);
		cin.ignore(1000, 10);

		if (size != 1 && size < 4) {
		cout << "SIZE OF BOARD MUST BE 1 OR GREATER THAN OR EQUAL TO 4\n\n";
		break;
        }
		initialize();
		break;

      case 'd': // display all solutions
      case 'D':
		cout << "\n...........   SOLUTIONS   ...........\n\n";
		solveQueen(0);
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

void solveQueen(int row)
{
  if (size == row)
  {
    cout << "Solution: ";
	for (int i = 0; i < size; i++)
	  cout << queen[i] << " ";
    cout << endl;
	outputBoard(queen,size);
  }
  else
  {
    for (int k = 0; k < size; k++)
    {
      if (canPlace(row, k))
      {
        queen[row] = k;
        solveQueen(row + 1);
      }
    }
  }
}

bool canPlace(int queen_number, int row_position)
{
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++)
	{
		// Get another queen's row_position
		int other_row_pos = queen[i];

		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
			other_row_pos == row_position - (queen_number - i) || // Same diagonal
			other_row_pos == row_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
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

void displyCheckerBoard(int size){
    cout << "*|";
    for (int i = 0; i < size; i++) {
        cout << (i%10) << "|";
    }
    cout << "*" << endl;
    for(int i=0; i < size; i++) {
        cout << (i%10) << "|";
        for(int j = 0; j < size; j++)
            cout << "_|";
        cout << (i%10) << endl;
    }
    cout << "*|";
    for (int i = 0; i < size; i++) {
        cout << (i%10) << "|";
    }
    cout << "*" << endl;

}

void initialize()
{
    for(int i = 0; i < size; i++)
        queen.push_back(0);
}



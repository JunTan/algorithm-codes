/*********************************************************
 * Description: Finds all solutions to N Queens
 *********************************************************/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int size = 8;
vector<int> queen;

void menu();
void outputBoard(vector<int>, int);
void solve_queen(int);
bool can_place(int, int);

void initialize() {
    for(int i = 0; i < size; i++)
        queen.push_back(0);
}

int main() {
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
				solve_queen(0);
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
/*void solve(int k)
{
	if (k == N) // We placed N-1 queens (0 included), problem solved!
	{
		// Solution found!

	}
	else
	{
		for (int i = 0; i < N; i++) // Generate ALL combinations
		{
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i))
			{
				position[k] = i;
				// Place another queen
				solve(k + 1);
			}
		}
	}
}*/

void solve_queen(int row)
{
    if (size == row)      //如果已经找到结果，则打印结果
    {
        cout << "Solution: ";
		for (int i = 0; i < size; i++)
			cout << queen[i] << " ";
		cout << endl;
    }
    else
    {
        for (int k = 0; k < size; k++)
        { //试探第row行每一个列
            if (can_place(row, k))
            {
                queen[row] = k;   //放置皇后
                solve_queen(row + 1);  //继续探测下一行
            }
        }
    }
}

bool can_place(int queen_number, int row_position)
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
 * input the n-queens\' solution array and its size
 * output the checker board
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


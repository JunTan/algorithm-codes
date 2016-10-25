/********************************************************
 * Finds all solutions to N Queens
 *********************************************************/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void menu();
void outputBoard(vector<int>, int);
void displyCheckerBoard(int);
bool isSafe(int, int);
void solve(int);
void initializer();

// not sure
int userSize = 8;
vector<int> userQueen;

int main() {
    
    int userSize = 0;
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
    initializer();
    
    string choice;
    while(true)
    {
        menu();
        cin >> choice;
        
        switch (choice[0]) {
            case 's': // change size
            case 'S':
                cout << "Enter Size of checker board: ";
                cin >> userSize;
                displyCheckerBoard(userSize);
                cin.ignore(1000, 10);
                
                
                if (userSize != 1 && userSize < 4) {
                    cout << "SIZE OF BOARD MUST BE 1 OR GREATER THAN OR EQUAL TO 4\n\n";
                    break;
                }
                initializer();
                break;
                
            case 'd': // display all solutions
            case 'D':
                solve(userSize);
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

bool isSafe(int queenAmount, int rowPosition){
    
    for (int i = 0; i < queenAmount; i++)
    {
        // Get another queen's row_position
        int other_row_pos = userQueen[i];
        
        // Now check if they're in the same row or diagonals
        if (other_row_pos == rowPosition || // Same row
            other_row_pos == rowPosition - (queenAmount - i) || // Same diagonal
            other_row_pos == rowPosition + (queenAmount - i))   // Same diagonal
            return false;
    }
    return true;
  
}

void solve(int row){
    if (userSize == row) // We placed N-1 queens (0 included), problem solved!
    {
        // Solution found!
        cout << "Solution: ";
        for (int i = 0; i < userSize; i++)
            cout << userQueen[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < userSize; i++) // Generate ALL combinations
        {
            // Before putting a queen (the k-th queen) into a row, test it for safeness
            if (isSafe(row, i))
            {
                userQueen[row] = i;
                // Place another queen
                solve(row + 1);
            }
        }
    }
}

void initializer()
{
    for(int i = 0; i < userSize; i++)
        userQueen.push_back(0);
}

// Name: Jun Tan
// Description: Read a maze file and search maze using recursion.
//				This program is for Backtracking exercise,
//              it does very little error checking.
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;


// Define the Maze class interface
class Maze
{
 public:
	// Constructors
	Maze() : num_rows(0), num_cols(0), start_row(0), start_col(0), end_row(0), end_col(0) {}
	~Maze() {}

	// Methods
	void ReadMaze(string name);
	void WriteMaze(string name);
	void PrintMaze();
	bool SearchMaze(int r, int c);
	void GetMaze(int r, int c, char &value);
	void SetMaze(int r, int c, char value);
	void GetStart(int &r, int &c);
	void SetStart(int r, int c);
	void GetEnd(int &r, int &c);
	void SetEnd(int r, int c);
	void PrintRout(string name);

 private:
	int num_rows, num_cols;
	int start_row, start_col;
	int end_row, end_col;
	char maze[100][100];
};


// Read maze from ascii file
void Maze::ReadMaze(string name)
{
	// Read maze.txt header
	ifstream fin;
	fin.open(name.c_str());
	fin >> num_rows >> num_cols;
	fin >> start_row >> start_col;
	fin >> end_row >> end_col;

	// Read maze.txt body
	string line;
	getline(fin, line);
	for (int r = 0; r < num_rows; r++)
	{
		getline(fin, line);
		for (int c = 0; c < num_cols; c++)
	 if (c < int(line.length()))
		 maze[r][c] = line[c];
	}
	fin.close();
}


// Write maze to ascii file
void Maze::WriteMaze(string name)
{
	// Write maze.txt header
	ofstream fout;
	fout.open(name.c_str());
	fout << num_rows << " " << num_cols << endl;
	fout << start_row << " " << start_col << endl;
	fout << end_row << " " << end_col << endl;

	// Write maze.txt body
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
	 fout << maze[r][c];
		fout << endl;
	}
	fout.close();
}


// Print maze to screen
void Maze::PrintMaze()
{
	// Print maze
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
	 cout << maze[r][c];
		cout << endl;
	}
}

void Maze:: PrintRout (string name)
{
    ofstream fout;
	fout.open(name.c_str());

    for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
	    {
	        if (maze[r][c] == '.')
	          cout << r << "  " << c<< endl;
	    }
		cout << endl;
	}
}

//-----------------------------------------------------------
// Get start location
//-----------------------------------------------------------
void Maze::GetStart(int &r, int &c)
{
	r = start_row;
	c = start_col;
}

//-----------------------------------------------------------
// Set start location
//-----------------------------------------------------------
void Maze::SetStart(int r, int c)
{
	start_row = r;
	start_col = c;
}

//-----------------------------------------------------------
// Get end location
//-----------------------------------------------------------
void Maze::GetEnd(int &r, int &c)
{
	r = end_row;
	c = end_col;
}

//-----------------------------------------------------------
// Set end location
//-----------------------------------------------------------
void Maze::SetEnd(int r, int c)
{
	end_row = r;
	end_col = c;
}

//-----------------------------------------------------------
// Recursively search maze
//-----------------------------------------------------------
bool Maze::SearchMaze(int r, int c)
{
	// Terminating conditions

	if ((r < 0) || (r >= num_rows) || (c < 0) || (c >= num_cols))
		return false;
	else if (maze[r][c] != ' ' && maze[r][c] != '@')
		return false;

	// Recursive conditions
    maze[r][c] = '-';
	if ((r==end_row) && (c==end_col) ||SearchMaze (r+1, c) || SearchMaze (r-1, c) || SearchMaze (r, c+1) || SearchMaze (r, c-1))
    {
        //this is a passage, and we need to do something else
        maze[r][c] = '.';
        return true;

    }

	else
        return false;

	return false;
}

//-----------------------------------------------------------
// Main program
//-----------------------------------------------------------
int main()
{
	Maze m;
	int r, c;
	m.ReadMaze("maze.txt");
	m.PrintMaze();
	m.GetStart(r, c);
	m.SearchMaze(r, c);
	m.PrintMaze();
	m.WriteMaze("maze_out.txt");
	m.PrintRout ("maze_out.txt");
		cout << "\n\aEnter to exit: ";
	cin.get();
}

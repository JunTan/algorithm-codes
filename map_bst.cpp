// Name: Jun Tan

#include <map>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

// Prototypes
void parse(string input, vector<string> &token, string del);
int tokenSize(string input, string del);

template<class T>
class BST{
  private:
    map<T, int> mymap;
    typedef _Rb_tree_node<pair<const T, int> > _Node;
  public:

    // tree print() starter (no argument) to pass the root node to the recursive print().
	// The root node can be located by finding the "grandest" parent of any node.
	// In this case, I used the first or leftest (in-order traversal) node.

    void print()const{
      const _Rb_tree_node_base * it = mymap.begin()._M_node;
      while(it -> _M_parent != mymap.end()._M_node){
         it = it -> _M_parent;
      }
      print(it, " ", " ");
    }

	// the recursive tree print() method
	void print(const _Rb_tree_node_base * it, std::string lpad, std::string rpad) const {
    std::string pad = lpad.substr(0, lpad.size() - 1);
	if (it == nullptr)	return;
	print(static_cast<const _Node *>(it)->_M_right, rpad + "    |", rpad + "     ");
	std::cout << pad <<((static_cast<const _Node *>(it) -> _M_color ==false? "+==":"+--" )) << std::setw(3)
            << static_cast<const _Node *>(it) -> _M_value_field.first << std::endl;
	print(static_cast<const _Node *>(it)->_M_left, lpad + "     ", lpad + "    |");
    }

	// The following node manipulation method utilize the map class methods
    void insert(const T & t){
    mymap.insert( pair<T,int>(t,100) );

    }

	void erase(const T & t) {
    mymap.erase(t );


	}

	void clear() {
    mymap.clear();


	}

	bool empty() {

		return (mymap.empty()); // compiler stub
	}
};

string del = ",";   // default delimiter
int trace = 0; // default trace mode, 0 - no trace, 1 - level 1, 2 - level 2.

void menu() {
	cout << "\n====BINARY SEARCH TREE MENU===="
		 << "\n	Delimiter is (" << del << ")"
		 << "\n	t - TOGGLE trace: (" << ( (trace==0) ? "OFF" : "ON" ) << ") LEVEL-" << trace
		 << "\n	p - PRINT tree"
		 << "\n	e - isEMPTY?"
		 << "\n	b - BUILD tree from a node list"
		 << "\n	i - INSERT"
		 << "\n	r - REMOVE"
		 << "\n	c - CLEAR"
		 << "\n	m - MENU - this menu"
		 << "\n	q - quit this menu\n";
}


int main(){

	//  Start up test with hard-wired data sets here:
	vector<string> temp; // temp holder for string tokens
	string del = ",";

	// Initialize the Binary Search Tree (BST) menu app.
	// create a default BST instance for testing
	BST<string> myBst;
	cout << "Create default BinarySearchTree (BST): " << endl;

	temp.clear();
	string input = "q,w,e,r,t,a,s,d,f,g,z,x,c,v";
	parse(input, temp, del);
	int tSize = tokenSize(input, del);

	cout << "Display the binary search tree as it is being built:\n	";
	for(int i =0; i<tSize; i++) {
		myBst.insert(temp[i]);
		cout << temp[i] << ( ( i < (tSize-1) ) ? "," : "\n" );
	}

	myBst.print();
	menu();

	while(true){
		// start the BST menu
		string usr_input;
		cout << "\nTL"<<trace<<" -->YOUR CHOICE-> ";
		getline(cin,usr_input);
		if(usr_input.length() > 1){
			cout << "\nSingle Character ONLY! " << endl;
		}
		else {
			char in = tolower(usr_input[0]);
			if(in == 'p') {
				if(myBst.empty()) cout << "This BST is EMPTY!\n";
				else myBst.print();
			}

			else if(in == 'e') {
				cout << "Binary search tree is: " << ((myBst.empty()) ? "EMPTY\n": "NOT EMPTY\n");
			}

			else if(in == 'i') {
				string input;
				cout << "Enter token: ";
				getline(cin, input);
				myBst.insert(input);
				if(trace > 0) {
					myBst.print();
					cout << "____________________________________\n";
				}
				cout << endl << input << " is inserted to the binary search tree.\n";
			}

			else if(in == 'r') {
				string input;
				cout << "Enter token: ";
				getline(cin, input);
				myBst.erase(input);
			}

			else if(in == 'c') {
				myBst.clear();
			}

			else if(in == 'b') {
				myBst.clear();
				temp.clear();
				string input;
				cout << "---- Enter a (\'" << del << "\' separated) string -> ";
				getline(cin, input);

				parse(input, temp, del);
				tSize = tokenSize(input,del);

				for(int i =0; i< tSize; i++) {
					myBst.insert(temp[i]);
					if(trace > 1) {
						myBst.print();
						cout << "____________________________________\n";
					}
				}
			}

			else if(in == 't') {
				trace = (trace + 1)%3;
			}

			else if(in == 'm') {
				menu();
			}

			else if(in == 'q') {
				exit(0);
			}

			else cout << "Invalid Input ! " << endl;
		}//else
	} //while(true)
}



void parse(string input, vector<string> &token, string del) {
	token.clear();
	int countDel =0;

	for(int i = 0; i< input.length(); i++) {
		if(input[i] == del[0])
		countDel++;
	}

	int tokenSize = countDel +1;
	for(int i=0; i< tokenSize; i++) {
		int x= input.find(del);
		token.push_back(input.substr(0,x));
		input = input.substr(x+1);
	}
}

// Utilities
int tokenSize(string input, string del)
{
	int size;
	int countDel =0;

	for(int i = 0; i< input.length(); i++) {
		if(input[i] == del[0])
		countDel++;
	}
	return size = countDel +1;
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool trace = false; // Not good, but easier this way.

//  displayHeap() helper method
//  Created by Tony Chern
//  Starter kit for COMSC210 Lab5 SP14
//	To show how a heap works
//  Using an upright drawing for a 4 level heap ( upto 15 nodes )
//  When better improvement is made, please share with me.

#define PARENT(i) ((i-1) / 2)
#define LINE_WIDTH 60.0

void displayHeap(vector<string> &heap, int realSize) {
	int num_nodes = heap.size();
    int print_pos[num_nodes]; // 40, 20, 60, 10, 30, 50, 70, 5, 15, ... (width 80)
    int i; // node
	int j; // node of level upto 1 2 4 8
	int k; // letter  in segment
	int pos; // letter position of level
	int x=1; //
	int level=0;
	char dash; // drawing symbol between left and right child
	queue<string> line;

	cout << "L1:          "; // the left margin
    print_pos[0] = 0;
	dash = '-';
    for(i=0,j=1; i<num_nodes; i++,j++) {
		if (i>realSize) dash = ' ';
        pos = print_pos[((i-1) / 2)] + ((i%2?-1:1)*(LINE_WIDTH/(pow(2,level+1))));

		for (k=0; k<pos-x-1; k++) {
			cout << (i==0||i%2?' ':dash);
			if( (i==realSize) && k >= ((pos-x-1)/2) ) dash = ' ';
			line.push(" ");
		}

		cout << heap[i];
		// draw the child link for last node
		if((i==num_nodes-1) && (i%2==1))
			for (k=0; k<(pos-x)/2; k++) cout << dash;
		line.push("|");

        print_pos[i] = x = pos;
        if (j==pow(2,level)) {
			cout << "\n             ";
			while(!line.empty()) {
				cout << line.front();
				line.pop();
			}
			level++;
			cout << "\nL" << level+1 << ":          ";
            x = 1; j = 0;
        }
    }
	cout << "\n\narray: ";
	int heap_size = heap.size();
	for (string ss : heap ) {
		cout << ss << ((heap_size <= 1) ? " " : ", ");
		heap_size--;
	}

	cout << "\n\n";
}

void menu()
{
	cout << "\n=== HeapSort Test Menu ===\n"
		 << "	TRACE is " << (trace?"ON\n":"OFF\n")
		 << "	new (,) delimited list \n"
		 << "	print (list) \n"
		 << "	build (heap) \n"
		 << "	view (heap) \n"
		 << "	sort (Heap Sort) \n"
		 << "	trace \n"
		 << "	quit \n"
		 << "	Enter your choice:\n";
}

void parse(string input, vector<string> &tokens, string del)
{
    tokens.clear();
    int countDel =0;

	for(int i = 0; i< input.length(); i++){
		if(input[i] == del[0])
		countDel++;
	}

	int tokenSize = countDel +1;

	for(int i=0; i< tokenSize; i++){
		int x= input.find(del[0]);
		tokens.push_back(input.substr(0,x));
		input = input.substr(x+1);
	}
}

int tokenSize(string input, string del)
{
	int size;
	int countDel =0;

	for(int i = 0; i< input.length(); i++){
		if(input[i] == del[0])
		countDel++;
	}

	return size = countDel + 1;
}

void heapRebuild(const int subTreeNodeIndex, vector<string> &items, int itemCount);

void heapSort(vector<string> &aHeap);

int main()
{
    string del = ",";
    cout << endl;
    string input = "1,3,5,7,9,2,4,6,8";
	vector<string> tokens, aHeap;

	parse(input, tokens, del);

	int tSize = tokenSize(input,del);
	cout << "array size: " << tSize << "\ncontent: ";
	for(int i =0; i<tSize; i++)
		cout << tokens[i] << (i<tSize-1?",  ":"\n");

	string answer;
	while(true){
		menu();
		getline(cin, answer);

		if( answer == "new"){
			aHeap.clear();
			cout << "New list: ";
			getline(cin, input);
			parse(input, tokens, del);

			tSize = tokenSize(input,del);
			cout << "List Size: " << tSize << "\nContent: ";
			for(int i =0; i<tSize; i++)
				cout << tokens[i] << (i<tSize-1?",  ":"\n");
		}

		else if( answer == "print"){
			cout << "array size: " << tSize << "\ncontent: ";
			for(int i =0; i<tSize; i++)
				cout << tokens[i] << (i<tSize-1?",  ":"\n");
		}

		else if(answer == "build"){
			aHeap.clear();
			aHeap = tokens;

			// Build a max-heap
			cout << " Build a Max-Heap by rebuilding all non-leaf nodes: \n";
			int n = aHeap.size();
			cout << "1!"<< endl;
			for (int index = n / 2; index >= 0; index--) {
                    cout << "2!"<< endl;
				heapRebuild(index, aHeap, n);
				if(trace) {
					displayHeap(aHeap, n);
					cout << " Heapify Heap( " << index << " )" << endl;
				}
			}
			cout << " Done building.\n";
		}

		else if (answer == "sort"){
			if(aHeap.empty()) cout << "you have to build the heap first!\n";
			else heapSort(aHeap);
		}

		else if (answer == "view"){
			displayHeap(aHeap, aHeap.size());
		}

		else if (answer == "trace"){
			if(!trace){
				cout << endl << "Trace mode is activated" ;
				trace = true;
			}
			else if(trace){
				cout << endl << "Trace mode is NOT activated" ;
				trace = false;
			}
		}

		else if(answer == "quit"){
			cout << endl << "GOOD BYE :) "<< endl;
			break;
		}

		else
			cout << endl<< "INVALID INPUT " ;
	}

	return 0;
}// main


void heapRebuild(const int subTreeNodeIndex, vector<string> &items, int itemCount){
  int l;
  int r;
  int largest;

  //left child index
  l = subTreeNodeIndex*2;
  r = subTreeNodeIndex*2+1;


  if ( (l <= itemCount) && (items[l]>items[subTreeNodeIndex]))
  {
    largest = l;
  }
  else
  {
      largest = subTreeNodeIndex;
  }

  if (r < itemCount && items[r] > items [largest])
  {
      largest = r;
  }

  if (largest != subTreeNodeIndex)
  {
    items[subTreeNodeIndex].swap(items[largest]);
    heapRebuild (largest, items, itemCount);
  }//end if
}  // end heapRebuild

void heapSort(vector<string> &aHeap){
  int n = aHeap.size ();

  for (int index = n/2; index > 0; index --)
  {
      cout << "22!"<< endl;
    heapRebuild (index, aHeap, n);
    cout << "88!"<< endl;
  }
  cout << "11!"<< endl;

  for (int i = n; i>=2; i --)
  {
      aHeap[1].swap(aHeap[i]);
      cout << "77!"<< endl;
      n = n-1;
      cout << "66!"<< endl;
      heapRebuild(1, aHeap, i);
      cout << "9!"<< endl;
  }
}  // end heapSort

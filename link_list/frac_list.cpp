// This program demonstrates the linked list template.
#include <iostream>
#include "list.h"
#include "frac.h"
using namespace std;

int main()
{
	// Define a LinkedList object.
	List<frac> list;

	// Define some frac objects.
	frac num1("5/4");
	frac num2("6/8");
	frac num3("8/9");

	// Store the frac objects in the list.
	list.insertNode(num1);
	list.insertNode(num2);
	list.insertNode(num3);

	// Display the values in the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;

	// Insert another frac object.
	cout << "Now inserting 7/2.\n";
	frac num4("7/2");
	list.insertNode(num4);

	// Display the values in the list.
	cout << "Here are the nodes now.\n";
	list.displayList();
	cout << endl;

	// Delete the last node.
	cout << "Now deleting the 5/4 node.\n";
	list.deleteNode(num1);

	// Display the values in the list.
	cout << "Here are the nodes left.\n";
	list.displayList();
	return 0;
}

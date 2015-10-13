#include "DLlist.h"




// This program demonstrates the linked list template.
#include <iostream>
using namespace std;

int main()
{
	// Define a LinkedList object.
	LinkedList list;
	ListNode r1 = ListNode("Alicia", "3");
	ListNode r2 = ListNode("Beatriz", "4");
	ListNode r3 = ListNode("Carlos", "5");
	ListNode r4 = ListNode("David", "6");
	ListNode r5 = ListNode("Nelson", "7");
	ListNode r6 = ListNode("Manuel", "8");

	list.insertNode(r1.name, r1.number);
	list.insertNode(r2.name, r2.number);
	list.insertNode(r3.name, r3.number);
	list.insertNode(r4.name, r4.number);
	list.insertNode(r5.name, r5.number);
	list.insertNode(r6.name, r6.number);


	// Display the values in the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;

	ListNode r7 = ListNode("Teresa", "9");
	list.insertNode(r7.name, r7.number);

	// Display the values in the list.
	cout << "Here are the nodes now.\n";
	list.displayList();
	cout << endl;

	// Delete the last node.
	cout << "Now deleting the last node.\n";
	list.deleteNode(r6.name);

	// Display the values in the list.
	cout << "Here are the nodes left.\n";
	list.displayList();

	cout << "#############" << endl;
	ListNode r8 = ListNode("Troya", "10");
	list.insertNode(r8.name, r8.number);
	list.displayList();
	cout << "#############" << endl;

	list.displayList();

	cin.get();
	return 0;

}


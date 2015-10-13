#pragma once
// A class template for holding a linked list.
// The node type is also a class template.
// --- MODIFIED by NDL
// --- nullptr changed to NULL
// --- <iostream added by did not work. I had to add std::cout and std::endl;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************


class ListNode
{
public:
	std::string name;           // Node value
	std::string number;
	ListNode *previous; //Pointer to previous node
	ListNode *next; // Pointer to the next node

					// Constructor
	ListNode(std::string na, std::string nu)
	{
		name = na;
		number = nu;
		previous = NULL;
		next = NULL;

	}
};

//*********************************************
// LinkedList class                           *
//*********************************************


class LinkedList
{
private:
	ListNode *head;   // List head pointer

public:
	// Constructor
	LinkedList()
	{
		head = NULL;
	}
	//exercise 1


	//implement once you have the head you have the list
	// Destructor
	~LinkedList();

	// Linked list operations
	//void appendNode(std::string&, std::string&);  //does not apply for Double linked list
	void insertNode(std::string&, std::string&);
	void deleteNode(std::string&);
	void displayList() const;
};



//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************


/*void LinkedList::appendNode(std::string& name, std::string& number)
{
	ListNode* newNode;  // To point to a new node
	ListNode* nodePtr;  // To move through the list

						// Allocate a new node and store newValue there.
	newNode = new ListNode(name, number);

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
	{
		head = newNode;
	}
	//exercise 2
	// if no nodes what is head?
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
			//exercise 3
		}


		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}*/

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

void LinkedList::displayList() const
{
	ListNode *nodePtr;  // To move through the list

						// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->name << std::endl;
		cout << nodePtr->number << std::endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

//template <class T>
void LinkedList::insertNode(std::string& name, std::string& number)
{
	ListNode *newNode;				// A new node
	ListNode *nodePtr;				// To traverse the list
	ListNode *previousNode = NULL; // The previous node

								   // Allocate a new node and store newValue there.
	newNode = new ListNode(name, number);

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;


		// Skip all nodes whose value is less than newValue.
		while (nodePtr != NULL && nodePtr->name < name)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			//exercise 4
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == NULL)
		{

			head = newNode;
			head->next = nodePtr;
			//exercise 5

		}
		else  // Otherwise insert after the previous node.
		{
			newNode->previous = previousNode;
			newNode->next = nodePtr;
			previousNode->next = newNode;
		}
	}
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

void LinkedList::deleteNode(std::string& name)
{
	ListNode *nodePtr;       // To traverse the list
							 //ListNode *previousNode;  // To point to the previous node

							 // If the list is empty, do nothing.
	if (!head)
		return;



	// Initialize nodePtr to head of list
	nodePtr = head;

	// Skip all nodes whose value member is 
	// not equal to num.
	while (nodePtr->next != NULL && nodePtr->name != name)
	{
		nodePtr = nodePtr->next;
	}
	//if the name is not in the list then return
	if (nodePtr->name != name)
		return;

	// If nodePtr is not at the end of the list, 
	// link the previous node to the node after
	// nodePtr, then delete nodePtr.
	if (nodePtr)
	{
		nodePtr->previous->next = nodePtr->next;

	}
	// Determine if the first node is the one.
	else if (!head->previous)
	{
		head = head->next;
	}
	delete nodePtr;

}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

LinkedList::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

						 // Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
#endif



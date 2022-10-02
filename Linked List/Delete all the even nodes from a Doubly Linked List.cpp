Remove all even parity nodes from a Doubly and Circular Singly Linked List

// C++ implementation to remove all
// the Even Parity Nodes from a
// doubly linked list

#include <bits/stdc++.h>

using namespace std;

// Node of the doubly linked list
struct Node {
	int data;
	Node *prev, *next;
};

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(Node** head_ref, int new_data)
{
	// Allocate the node
	Node* new_node
		= (Node*)malloc(sizeof(struct Node));

	// Insert the data
	new_node->data = new_data;

	// Since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// Link the old list off the new node
	new_node->next = (*head_ref);

	// Change the prev of
	// head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// Move the head to point
	// to the new node
	(*head_ref) = new_node;
}

// Function that returns true if count
// of set bits in x is even
bool isEvenParity(int x)
{
	// parity will store the
	// count of set bits
	int parity = 0;
	while (x != 0) {
		if (x & 1)
			parity++;
		x = x >> 1;
	}

	if (parity % 2 == 0)
		return true;
	else
		return false;
}

// Function to delete a node
// in a Doubly Linked List.
// head_ref --> pointer to head node pointer.
// del --> pointer to node to be deleted
void deleteNode(Node** head_ref, Node* del)
{
	// Base case
	if (*head_ref == NULL || del == NULL)
		return;

	// If the node to be
	// deleted is head node
	if (*head_ref == del)
		*head_ref = del->next;

	// Change next only if node to be
	// deleted is not the last node
	if (del->next != NULL)
		del->next->prev = del->prev;

	// Change prev only if node to be
	// deleted is not the first node
	if (del->prev != NULL)
		del->prev->next = del->next;

	// Finally, free the memory
	// occupied by del
	free(del);

	return;
}

// Function to to remove all
// the Even Parity Nodes from a
// doubly linked list
void deleteEvenParityNodes(
	Node** head_ref)
{
	Node* ptr = *head_ref;
	Node* next;

	// Iterating through
	// the linked list
	while (ptr != NULL) {
		next = ptr->next;

		// If node's data's parity
		// is even
		if (isEvenParity(ptr->data))
			deleteNode(head_ref, ptr);

		ptr = next;
	}
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	if (head == NULL) {
		cout << "Empty list\n";
		return;
	}

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver Code
int main()
{

	Node* head = NULL;

	// Create the doubly linked list
	// 18 <-> 15 <-> 8 <-> 9 <-> 14
	push(&head, 14);
	push(&head, 9);
	push(&head, 8);
	push(&head, 15);
	push(&head, 18);

	// Uncomment to view the list
	// cout << "Original List: ";
	// printList(head);

	deleteEvenParityNodes(&head);

	// Modified List
	printList(head);
}

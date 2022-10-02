Delete all Prime nodes from a Singly Linked List

// C++ implementation to delete all
// prime nodes from the singly
// linked list
#include <bits/stdc++.h>

using namespace std;

// Node of the singly linked list
struct Node {
	int data;
	Node* next;
};

// function to insert a node at the beginning
// of the singly Linked List
void push(Node** head_ref, int new_data)
{
	// allocate node
	Node* new_node = (Node*)malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to check if a number is prime
bool isPrime(int n)
{
	// Corner cases
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

// function to delete a node in a singly Linked List.
// head_ref --> pointer to head node pointer.
// del --> pointer to node to be deleted
void deleteNode(Node** head_ref, Node* del)
{
	// base case
	struct Node* temp = *head_ref;
	if (*head_ref == NULL || del == NULL)
		return;

	// If node to be deleted is head node
	if (*head_ref == del){
		*head_ref = del->next;
		return;
	}
	// traverse list till not found
	// delete node
	while (temp->next != del) {
		temp = temp->next;
	}
	// copy address of node
	temp->next = del->next;
	// Finally, free the memory occupied by del
	free(del);

	return;
}

// function to delete all prime nodes
// from the singly linked list
void deletePrimeNodes(Node** head_ref)
{
	Node* ptr = *head_ref;
	Node* next;

	while (ptr != NULL) {
		next = ptr->next;
		// if true, delete node 'ptr'
		if (isPrime(ptr->data))
			deleteNode(head_ref, ptr);
		ptr = next;
	}
}

// function to print nodes in a
// given singly linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program
int main()
{
	// start with the empty list
	Node* head = NULL;

	// create the linked list
	// 15 -> 16 -> 7 -> 6 -> 17
	push(&head, 17);
	push(&head, 7);
	push(&head, 6);
	push(&head, 16);
	push(&head, 5);

	cout << "Original List: ";
	printList(head);

	deletePrimeNodes(&head);

	cout << "\nModified List: ";
	printList(head);
}

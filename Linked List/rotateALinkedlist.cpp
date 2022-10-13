// C++ program to rotate
// a linked list counter clock wise

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

// This function rotates a linked list
// counter-clockwise and updates the
// head. The function assumes that k is
// smaller than size of linked list.
// It doesn't modify the list if
// k is greater than or equal to size
void rotate(Node** head_ref, int k)
{
	if (k == 0)
		return;

	Node* current = *head_ref;

	int count = 1;
	while (count < k && current != NULL) {
		current = current->next;
		count++;
	}

	if (current == NULL)
		return;

	Node* kthNode = current;

	while (current->next != NULL)
		current = current->next;

	current->next = *head_ref;

	*head_ref = kthNode->next;

	kthNode->next = NULL;
}

/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}

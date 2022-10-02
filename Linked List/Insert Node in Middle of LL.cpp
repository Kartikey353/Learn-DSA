// C++ implementation to insert node at the middle
// of the linked list
#include <bits/stdc++.h>

using namespace std;

// structure of a node
struct Node {
	int data;
	Node* next;
};

// function to create and return a node
Node* getNode(int data)
{
	// allocating space
	Node* newNode = (Node*)malloc(sizeof(Node));

	// inserting the required data
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// function to insert node at the middle
// of the linked list
void insertAtMid(Node** head_ref, int x)
{
	// if list is empty
	if (*head_ref == NULL)
		*head_ref = getNode(x);
	else {

		// get a new node
		Node* newNode = getNode(x);

		Node* ptr = *head_ref;
		int len = 0;

		// calculate length of the linked list
		//, i.e, the number of nodes
		while (ptr != NULL) {
			len++;
			ptr = ptr->next;
		}

		// 'count' the number of nodes after which
		// the new node is to be inserted
		int count = ((len % 2) == 0) ? (len / 2) :
									(len + 1) / 2;
		ptr = *head_ref;

		// 'ptr' points to the node after which
		// the new node is to be inserted
		while (count-- > 1)
			ptr = ptr->next;

		// insert the 'newNode' and adjust the
		// required links
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	// Creating the list 1->2->4->5
	Node* head = NULL;
	head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(4);
	head->next->next->next = getNode(5);

	cout << "Linked list before insertion: ";
	display(head);

	int x = 3;
	insertAtMid(&head, x);

	cout << "
Linked list after insertion: ";
	display(head);

	return 0;
}

/*
**
** XOR linked list is a memory efficient version of Doubly Linked List
** (because the list uses bitwise XOR operation to save space for one address) 
** that can be created using only one space for address field with every node.
** In the XOR linked list, instead of storing actual memory addresses, 
** every node stores the XOR of addresses of previous and next nodes.
**
*/

#include <bits/stdc++.h>
using namespace std;

// Class to implement node
class XorListNode
{
    public:
    char val;
    XorListNode *npx; /* XOR of next and previous node */
    XorListNode()
    {
        val = ' ';
        npx = NULL;
    }
    XorListNode(char v)
    {
        val = v;
        npx = NULL;
    }
};

/* returns XORed value of the node addresses */
XorListNode* XOR(XorListNode *x, XorListNode *y)
{
    return (XorListNode*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void traverseForward(XorListNode *node)
{
    XorListNode* prev = NULL;
    XorListNode* curr = node;
    while (curr != NULL)
    {
        // print current node
        cout << " " << curr->val;

        XorListNode *temp = XOR(curr->npx, prev);
        prev = curr;
        curr = temp;
    }
}

void traverseBackward(XorListNode *node)
{
    XorListNode* next = NULL;
    XorListNode* curr = node;
    while (curr != NULL)
    {
        cout << " " << curr->val;
        XorListNode *temp = XOR(curr->npx, next);
        next = curr;
        curr = temp;
    }
}

/* Inserting a new node at the beginning of the XORed linked list 
and makes the newly inserted node as head */
void insert(XorListNode *&head, char data)
{
    // Allocate memory for new node 
    XorListNode *newNode = new XorListNode(data);

    /* Since new node is being inserted at the 
	beginning, npx of new node will always be 
	XOR of current head and NULL */
    newNode->npx = head;

    /* If linked list is not empty, then npx of 
	current head node will be XOR of new node 
	and node next to current head */
    if (head != NULL)
    {
        // *(head_ref)->npx is XOR of NULL and next. 
		// So if we do XOR of it with NULL, we get next 
        head->npx = XOR (head->npx, newNode);
    }

    // Change head
    head = newNode;
}

int main ()
{
    XorListNode *head = NULL;
    insert(head, 'E'); // E
    XorListNode* end = head; // points to 'E'
    insert(head, 'D'); // D->E
    insert(head, 'C'); // C->D->E
    insert(head, 'B'); // B->C->D->E
    insert(head, 'A'); // A->B->C->D->E

    cout << "Linked List Traversal in Forward Direction:";
    traverseForward(head);
    cout << endl;

    cout << "Linked List Traversal in Backward Direction:";
    traverseBackward(end);
    return 0;
}
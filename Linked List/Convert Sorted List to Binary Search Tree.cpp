#109. Convert Sorted List to Binary Search Tree(Leet Code)

class Solution
{
public:

  ListNode* mid(ListNode* &head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = head;
    // Two pointer approach
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(prev != NULL)
        prev->next = NULL;
    
    return slow;// returns mid pointer
}


TreeNode* sortedListToBST(ListNode* head) 
{
    if(head == NULL) return NULL;
    ListNode* middle = mid(head);
    TreeNode* root = new TreeNode(middle->val);
    
    if(head == middle) 
        return root;
    
    root->left = sortedListToBST(head);// mid of left sub-tree
    root->right = sortedListToBST(middle->next);// mid of right sub-tree
    
    return root;
}
};// T.C=O(nlogn)
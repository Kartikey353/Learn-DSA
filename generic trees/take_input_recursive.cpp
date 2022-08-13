#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> childreen;
    TreeNode(T data)
    {
        this->data = data;
    }
    void print()
    {
        cout << this->data << " ";
        for (int i = 0; i < this->childreen.size(); i++)
            cout << this->childreen[i]->data << " ";
    }

    TreeNode<int> *createNode(int data)
    {
        TreeNode<int> *root = new TreeNode<int>(data);
        cout << "Enter number of child";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter value";
            int datavalue;
            cin >> datavalue;
            TreeNode<int> *child = createNode(datavalue);
            root->childreen.push_back(child);
        }
        return root; 
    } 
};

int main()
{ 
    int value;
    cout<<"enter root data";
    cin>>value; 
    TreeNode<int> *root=new TreeNode<int>(value); 
    root=root->createNode(value);   
    cout<<root->data;
    for (int i = 0; i < root->childreen.size(); i++)
        root->childreen[i]->print(); 
    return 0;
}

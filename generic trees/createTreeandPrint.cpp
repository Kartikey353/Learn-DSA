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
        cout << this->data<<" ";
        for (int i = 0; i < this->childreen.size(); i++)
            cout << this->childreen[i]->data<<" ";
    }
};

int main()
{
    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *root1 = new TreeNode<int>(5);
    TreeNode<int> *root2 = new TreeNode<int>(4);
    TreeNode<int> *root3 = new TreeNode<int>(3);
    TreeNode<int> *root11 = new TreeNode<int>(2);
    TreeNode<int> *root12 = new TreeNode<int>(1);
    TreeNode<int> *root21 = new TreeNode<int>(0);
    TreeNode<int> *root22 = new TreeNode<int>(8);
    root->childreen.push_back(root1);
    root->childreen.push_back(root2);
    root->childreen.push_back(root3);
    root1->childreen.push_back(root11);
    root1->childreen.push_back(root12);
    root2->childreen.push_back(root21);
    root2->childreen.push_back(root22);
    cout << root->data<<"\n";
    for (int i = 0; i < root->childreen.size(); i++)
        root->childreen[i]->print();
    return 0;
}

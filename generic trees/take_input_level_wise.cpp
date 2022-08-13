#include <bits/stdc++.h>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> childreen;
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
};

TreeNode<int>* take_input_level_wise()
{ 
    cout<<"enter value of root"; 
    int data;
    cin>>data; 
    TreeNode<int>*root=new TreeNode<int>(data);
    queue<TreeNode<int> *>queuedata; 
    queuedata.push(root); 

    while(!queuedata.empty())
    {
        cout<<"enter number of child"<<queuedata.front()->data;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"enter the value of"<<i<<" child";
            int value;
            cin>>value; 
            TreeNode<int>*child=new TreeNode<int>(value); 
            queuedata.front()->childreen.push_back(child);
            queuedata.push(child);
        } 
        queuedata.pop();
    } 
    return root;
}

int main()
{
   auto root=take_input_level_wise(); 
    cout<<root->data<<" ";
    for (int i = 0; i < root->childreen.size(); i++)
        root->childreen[i]->print(); 
    return 0;
}

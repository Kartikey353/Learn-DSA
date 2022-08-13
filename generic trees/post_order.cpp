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

    void print_level_wise()
    {
        queue<TreeNode<int> *> queuedata;
        queuedata.push(this);
        while (!queuedata.empty())
        {
            cout << queuedata.front()->data << ":";
            for (int i = 0; i < queuedata.front()->childreen.size(); i++)
            {
                cout << queuedata.front()->childreen[i]->data << " , ";
                queuedata.push(queuedata.front()->childreen[i]);
            }
            cout << endl;
            queuedata.pop();
        }
    }
};

TreeNode<int> *take_input_level_wise()
{
    cout << "enter value of root";
    int data;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> queuedata;
    queuedata.push(root);

    while (!queuedata.empty())
    {
        cout << "enter number of child" << queuedata.front()->data;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "enter the value of" << i << " child";
            int value;
            cin >> value;
            TreeNode<int> *child = new TreeNode<int>(value);
            queuedata.front()->childreen.push_back(child);
            queuedata.push(child);
        }
        queuedata.pop();
    }
    return root;
} 
 
void postorder(TreeNode<int> *root)
{
    if(root==NULL)
    return;  
    cout<<root->data;
    for(int i=0;i<root->childreen.size();i++)
    {
         postorder(root->childreen[i]);
    }
}

int main()
{
    auto root = take_input_level_wise(); 
   postorder(root);
    return 0;
}
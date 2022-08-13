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
    ~TreeNode(){
        for(int i=0;i<childreen.size();i++)
        {
            delete childreen[i];
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

int main()
{
    auto root = take_input_level_wise(); 
    delete root;
    return 0;
} 



// # Learn-DSA 
// This is series of learning Dsa help you to get knowledge with the help of codes. 

// ##Clone/Download  the repo 

// Type following command on gitbash or terminal\

// ```bash 
// git clone  


// https://github.com/Kartikey353/Learn-DSA.git
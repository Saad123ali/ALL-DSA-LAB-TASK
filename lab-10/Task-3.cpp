#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
 
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if(root == nullptr)
    {
        return createNode(value);
    }

    if(value <  root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTravrsal(Node* root)
{
    if(root == nullptr) return;
    inOrderTravrsal(root->left); // visit left subtree
    cout<<root->data<<" ";       // print the node value
    inOrderTravrsal(root->right); // visit right subtree
}

void preOrderTravrsal(Node* root)
{
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preOrderTravrsal(root->left);
    preOrderTravrsal(root->right);
}

void postOrderTravrsal(Node* root)
{
    if(root == nullptr) return;
    postOrderTravrsal(root->left);
    postOrderTravrsal(root->right);
    cout<<root->data<<" ";
}


int main()
{
    Node* root = nullptr;  //start with an empty tree 
    
    int value, n;
    cout<<"Enter the number do you want to insert? ";
    cin>>n;

    for(int i =0; i < n; i++)
    {
        cout<<"Enter the value : "<<i +1<<" : "<<" ";
        cin>>value;
        root = insert(root,value);
    }
    cout<<"In-Order traversal of the BST "<<endl;
    inOrderTravrsal(root);
    cout<<endl;
    cout<<"Pre-Order traversal of the BST "<<endl;
    preOrderTravrsal(root);
    cout<<endl;
    cout<<"Post-Order traversal of the BST "<<endl;
    postOrderTravrsal(root);
    cout<<endl;

    return 0;
}
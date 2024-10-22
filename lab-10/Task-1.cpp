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

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout<<"In-Order traversal of the BST "<<endl;
    inOrderTravrsal(root);
    cout<<endl;
    cout<<"Pre-Order traversal of the BST "<<endl;
    preOrderTravrsal(root);
    cout<<endl;
    cout<<"Post-Order traversal of the BST "<<endl;
    postOrderTravrsal(root);

    return 0;
}
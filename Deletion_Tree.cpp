#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

struct node{
    int key;
    struct node *left,*right;
};

struct node* newNode(int data)
{
    struct node *temp = new node;
    temp->key=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* insertt(struct node* root,int data)
{
    if(root==NULL){return newNode(data);}
    if(data < root->key)
    {
        root->left=insertt(root->left,data);
    }
    else
    {
        root->right=insertt(root->right,data);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

struct node* minDistance(struct node* root)
{
    struct node* temp= root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

struct node* deleteNode(struct node* root,int data)
{
    if(root==NULL){return root;}
    if(data < root->key)
    {
        root->left = deleteNode(root->left,data);
    }
    else if(data > root->key)
    {
        root->right = deleteNode(root->right,data);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp = minDistance(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);

    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insertt(root, 50);
    root = insertt(root, 30);
    root = insertt(root, 20);
    root = insertt(root, 40);
    root = insertt(root, 70);
    root = insertt(root, 60);
    root = insertt(root, 80);

    cout<<"Inorder traversal of the given tree "<<endl;
    inorder(root);

    cout<<endl<<"Delete 20"<<endl;
    root = deleteNode(root, 20);
    cout<<"Inorder traversal of the given tree "<<endl;
    inorder(root);

    cout<<endl<<"Delete 30"<<endl;
    root = deleteNode(root, 30);
    cout<<"Inorder traversal of the given tree "<<endl;
    inorder(root);

    cout<<endl<<"Delete 50"<<endl;
    root = deleteNode(root, 50);
    cout<<"Inorder traversal of the given tree "<<endl;
    inorder(root);

    return 0;
}

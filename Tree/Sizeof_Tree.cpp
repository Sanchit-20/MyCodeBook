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
    struct node* temp = new node;
    temp->key=data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root,int data)
{
    if(root==NULL){return newNode(data);}
    if(data < root->key)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
int sizeoftree(struct node* root)
{
    if(root!=NULL)
    {
        return( sizeoftree(root->left) + sizeoftree(root->right) + 1);
    }
    else
    {
        return 0;
    }
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
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);cout<<endl;
    cout<<sizeoftree(root);
}

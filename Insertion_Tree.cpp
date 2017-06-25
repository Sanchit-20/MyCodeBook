#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

struct node{
    int data;
    struct node *left, *right;
};

struct node *newNode(int x)
{
    //struct node *temp =(struct node *)malloc(sizeof(struct node));
    struct node *temp = new node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

struct node* insert(struct node* root,int key)
{
    if(root==NULL){return newNode(key);}
    if(key<root->data)
    {
        root->left=insert(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=insert(root->right,key);
    }
    return root;
};

void inorder(struct node* root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}

int main()
{
	struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);

    return 0;
}

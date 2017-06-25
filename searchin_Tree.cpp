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

int search(struct node* root,int data)
{
    if(root!=NULL)
    {
        if(root->key==data)
        {
            return 1;
        }
        else if(data<root->key)
        {
            return search(root->left,data);
        }
        else
        {
            return search(root->right,data);
        }
    }
    else
    {
        return -1;
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
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        y=search(root,x);
        if(y==1)
        {
            cout<<"Yes "<<endl;
        }
        else
        {
            cout<<"No "<<endl;
        }
    }
}

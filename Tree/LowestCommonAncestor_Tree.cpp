#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

struct node{
    int key;
    struct node * left,*right;
};

struct node* newNode(int data)
{
    struct node* temp=new node;
    temp->key=data;
    temp->left = temp->right =NULL;
    return temp;
}
struct node* insert(struct node* root,int data)
{
    if(root==NULL){return newNode(data);}
    if(data<root->key)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

struct node* LCA(struct node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->key==a || root->key==b)
    {
        return root;
    }
    struct node* left_lca=LCA(root->left,a,b);
    struct node* right_lca=LCA(root->right,a,b);
    if(left_lca!=NULL && right_lca!=NULL){return root;}

    return (left_lca!=NULL)?left_lca:right_lca;
}
bool find(struct node* root,int a)
{
    if(root==NULL)
        return false;
    if(root->key==a || find(root->left,a) || find(root->right,a))
        return true;

        return false;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 100);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 1);
    root = insert(root, 25);
    root = insert(root, 35);
    int n,a,b;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        bool x,y;
        x=find(root,a);
        y=find(root,b);
        if(x==true && y==true)
        {cout<<LCA(root,a,b)->key<<endl;}
        else if(x==true && y==false)
        {
            cout<<b<<" is absent "<<endl;
        }
        else if(x==false && y==true)
        {
            cout<<b<<" is absent "<<endl;
        }
        else
        {
            cout<<a<<" and "<<b<<"both are absent "<<endl;
        }
    }
}

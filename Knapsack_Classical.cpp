#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ma 30005

int wt[100],val[100],n,x;
int knapsack(int w,int n)
{
    if(n==0 || w==0)
        return 0;
    if(w<wt[n-1])
        return knapsack(w,n-1);
    else
    {
        return max(val[n-1]+knapsack(w-wt[n-1],n-1), knapsack(w,n-1) );
    }
}

int main()
{
	int a;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>val[i]>>wt[i];
    }
    cin>>x;
    a=knapsack(x,n);
    cout<<a;
    return 0;

}

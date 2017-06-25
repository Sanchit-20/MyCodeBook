#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ma 30005

ll wt[1001],val[1001],dp[1001]={0};

int knapsack(int w,int n)
{
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(wt[j]<=i)
			{
				dp[i]=max(dp[i],val[j]+dp[i-wt[j]] );
			}
		}
	}
	return dp[w];
}

int main()
{
	ll n,w,a;
	cin>>n>>w;
	for(int i=0;i<n;i++)
	{
		cin>>wt[i]>>val[i];
	}
	a=knapsack(w,n);
	cout<<a;
}


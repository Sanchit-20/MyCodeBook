#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
#define mod 1000000007

ll a[100001];

void sieve(ll n)
{
	for(ll i=2;i*i<=n;i++)
	{
		if(a[i]==0)
		{
			for(ll j=2*i;j<=n;j+=i)
			{
				a[j]=1;
			}
		}
	}
	for(ll i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			cout<<i<<" ";
		}
	}
}

int main()
{
	ll n;
	cin>>n; 
	sieve(n);
	
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
	ll n,a[1000],l,r,m,s;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cin>>s;
	l=1;r=n;ll ans=-1;
	while(l<=r)
	{
		m=l+(r-l)/2;
		if(a[m]==s){ans=m;}
		if(a[m]<s){l=m+1;}
		else{r=m-1;}
	}
	cout<<ans;
	
}

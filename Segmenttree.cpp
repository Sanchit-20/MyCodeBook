#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000
ll tree[100001],input[100001];

void build(int low,int high,int pos)
{
	if(low==high)
	{
		tree[pos]=input[low];
		return;
	}
	int mid;
	mid=(low+high)/2;
	build(low,mid,2*pos+1);
	build(mid+1,high,2*pos+2);
	tree[pos] = min( tree[2*pos+1] , tree[2*pos+2] );
}

int qsearch(int qlow,int qhigh,int low,int high,int pos)
{
	int mid;
	if(qlow<=low && qhigh>=high)  // full overlap
	{
		return tree[pos];
	}
	if(qlow>high || qhigh<low) // no overlap
	{
		return MAX;
	}
	mid= (low+high)/2; // partial overlap
	return min( qsearch(qlow,qhigh,low,mid,2*pos+1), qsearch(qlow,qhigh,mid+1,high,2*pos+2) );
}

int main()
{
	ll n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
	}
	build(0,n-1,0);
	int a,b,x;
	//cout<<"hello"<<endl;
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		x=qsearch(a,b,0,n-1,0);
		cout<<x<<endl;
	}
}

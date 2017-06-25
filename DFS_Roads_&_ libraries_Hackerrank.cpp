#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
#define ll long long int

vector< vector<int> > v(100001);
vector<bool> visited(100001,0);

ll dfs(ll vertex)
{
	ll count;
	visited[vertex]=1;
	count=1;
	for(ll i=0;i<v[vertex].size();i++)
	{
		if(visited[v[vertex][i]]==0)
		{
			count+=dfs(v[vertex][i]);
		}
	}
	return count;
}
int main()
{
	ll t,n,q,l,r,a,b,nodes=0;
	cin>>t;
	while(t--)
	{
		cin>>n>>q>>l>>r;
		ll cost,sum=0,nodes;
		for(ll i=0;i<q;i++)
		{
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				nodes=dfs(i);
				if(l<=r)
				{
					cost=nodes*l;
				}
				else
				{
					cost=l+(nodes-1)*r;
				}
				sum+=cost;
			}
		}
		cout<<sum<<endl;
	}
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 1000000
#define V 3001


//vector< pair<int,int> > graph[V];

int distance(int dist[], bool sptSet[],int n)
{
	int m=MAX;int index;
	for(int i=1;i<=n;i++)
	{
		if(sptSet[i]==false && dist[i]<=m)
		{
			m=dist[i];
			index=i;
		}
	}
	return index;
}

void dijkstra(vector< pair<int,int> > graph[V],int s,int n)
{
	int dist[n+1];
	bool sptSet[n+1];

	for(int i=1;i<=n;i++)
	{
		sptSet[i]=false;
		dist[i]=MAX;
	}

	dist[s]=0;

	for(int j=1;j<n;j++)
	{
		int u;
		u=distance(dist,sptSet,n);
		sptSet[u]=true;
        vector< pair<int,int> >::iterator v;
		for(v=graph[u].begin();v!=graph[u].end();v++)
		{
			if( sptSet[(*v).first]==false && dist[u]+(*v).second <dist[(*v).first] && dist[u]!=MAX)
			{
				dist[(*v).first]=dist[u]+ (*v).second;
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(i!=s)
		{
		    if(dist[i]!=MAX)
			{cout<<dist[i]<<" ";}
			else{cout<<"-1 ";}
		}
	}
	cout<<endl;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	    vector< pair<int,int> > graph[V];
		ll n,a,b,s,x,e;
		cin>>n>>e;
		for(int i=1;i<=e;i++)
		{
			cin>>a>>b>>x;
			graph[a].push_back(make_pair(b,x));
			graph[b].push_back(make_pair(a,x));
		}
		cin>>s;
		dijkstra(graph,s,n);
	}
}

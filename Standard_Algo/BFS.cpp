// Can be used to find shortest path in an unweighted graph from given source.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld",x)
#define rep(i,from,to) for(int i=from;i<=to;i++)
#define repd(i,from,to) for(int i=from;i>=to;i--)
#define MAX 10000
#define mod 1000000007
#define infi 10000000
#define opt std::ios_base::sync_with_stdio(false)
typedef long long int ll;
ll powm(ll base,ll exp) {ll ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;} 


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
        int n,m;
        cin>>n>>m;
        vector<int> v[1005];
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        } 
        int s;
        cin>>s;
        bool visited[1005];
        int d[1005];
        for(int i=1;i<=n;i++)
        {
            visited[i]=false;
            d[i]=0;
        }
        queue<int> q;
        q.push(s);d[s]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<v[u].size();i++)
            {
                if(!visited[v[u][i]])
                {
                    q.push(v[u][i]);
                    d[v[u][i]]=d[u]+1;
                    visited[v[u][i]]=true;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i==s)continue;
            if(d[i]==0)cout<<-1<<" ";
            else cout<<6*d[i]<<" ";
        }
        cout<<endl;
   }
}

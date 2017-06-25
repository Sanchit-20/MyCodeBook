#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define MAX 1000000

int main()
{
	ll n,ar[100001],s;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cin>>s;
    sort(ar,ar+n);
    ll l,r,m,ans;
    l=0;r=n-1;ans=-1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(ar[m]==s)
        {
            ans=m;
            r=m-1;
        }
        if(ar[m]<s)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    if(ans!=-1)
    {
        ll b=ans;
        //cout<<"First occurence of "<<s<<" is at "<<ans<<" index"<<endl;
        l=0;
        r=n-1;ans=-1;
        //cout<<" l r "<<l<<" "<<r<<endl;
        while(l<=r)
        {

            m=(l+r)/2;
            if(ar[m]==s)
            {
                //cout<<"hello ";
                ans=m;
                l=m+1;
            }
            else if(ar[m]<s)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
            //cout<<" l r m "<<l<<" "<<r<<" "<<m<<endl;
        }
        //cout<<"Last occurence of "<<s<<" is at "<<ans<<" index"<<endl;
        cout<<ans-b+1<<endl;
    }
    else
    {
        cout<<"Not exists "<<endl;
    }
}

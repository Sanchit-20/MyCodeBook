#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int circular_search(int a[],int n,int s)
{
    int l=0,h=n-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==s)
        {
            return mid;
        }
        if(a[mid]<=a[h])
        {
            if(s>a[mid] && s<=a[h])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        else
        {
            if(s>=a[l] && s<a[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
}

int main()
{
	int n,a[100],s;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>s;
    cout<<"Index is "<<circular_search(a,n,s)<<endl;
}

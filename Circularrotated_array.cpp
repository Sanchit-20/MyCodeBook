#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int findrotation(int a[],int n)
{
    int l=0,h=n-1,mid,next,previous;
    while(l<=h)
    {
        if(a[l]<=a[h])  //case 1
         {return l;}
        mid=(l+h)/2;  next=(mid+1)%n; previous=(mid-1+n)%n;
        if(a[mid]<=a[next] && a[mid]<=a[previous])   // case2
        {
            return mid;
        }
        else if(a[mid]<=a[h])  // case 3
        {
            h=mid-1;
        }
        else if(a[mid]>=a[l])  // case 4
        {
            l=mid+1;
        }
    }
    return -1;
}

int main()
{
	int n,a[100];
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"No. of rotations is "<<findrotation(a,n)<<endl;
}

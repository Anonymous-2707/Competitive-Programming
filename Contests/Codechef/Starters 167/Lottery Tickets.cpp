#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define N 1000000007
#define pb push_back
#define po pop_back
#define endl "\n"

// ********************************************************************
// I don't want to explain every part of the code in detail.
// As I strongly believe understanding code on your own is far better than learning it through YT videos.
// So Exercise your brain and push its limits !! 
// *********************************************************************

// Logic :

// Let's try to find which range of values are possible as answers !!
// So let's assume that l=1 and r=1e6 as all of them are possible values of X. let's initialize num as a[0].
// Now given that all the elements are distint so let's sort the given array and try to find the position of num in sorted array. 
// Let's assume we found it in i'th position.
// If there is an element before it then we need the elements which are closer or equi distance from this a[i]. 
// So we can update l as (a[i-1]+a[i]+1)/2.
// Example: If we think of (1,4) then (1+4+1)/2=3 this is what we want !!
// If there is any element after a[i] then we can update r as (a[i]+a[i+1])/2. 
// Example: If we think of (4,7) (4+7)/2 =5 4,5 are nearer to 4 where as 6 is nearer to 7 so it can't be in the range.
// As we have the range s numbber of possibilities will be r-l+1.   


int main()
{
  IOS;
  ll t; cin>>t;
  for(int i=0;i<t;i++)
  {
    ll n; cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll num=a[0];
    sort(a,a+n);
    ll l=1; ll r=1e6; 
    for(int i=0;i<n;i++)
    {
      if(a[i]==num)
      {
         if(i-1>=0) l=(a[i-1]+a[i]+1)/2;
         if(i+1<n) r=(a[i]+a[i+1])/2;
      }
    }
    cout<<r-l+1<<endl;
  }
}

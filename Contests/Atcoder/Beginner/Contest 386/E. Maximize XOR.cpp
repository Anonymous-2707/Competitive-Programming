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

// Lets see the constraints,(nCk) will be in the order of 1e6
// Actually I tried to submit it by bruteforce and some cases are giving TLE...
// So Tried to Optimize a little by taking the suffix XOR of the given array and it passed !! 

// As we have to exactly take k so we have to leave (n-k);
// So consider a global variable ans and then brute force the question with the possibility of taking and not taking 
// Taking Conditions
  //  1.If there are nothing to leave then we should take all so in a single step we can XOR with and Suff[idx] and reach idx==n (leave==0) !!
  //  2.Normally taking the element at a given index idx if number of elements left are greater than what we can leave (leave<n-idx) !!
// Not take condition 
  //  1.if we have a possibility to leave we will leave and move forward (leave>0) !!
  //  2.if we have to leave all of them then just leave and rach the end (leave==n-idx) !!

// So we can get the answer !!

ll ans=0;

void solve(ll idx, ll leave, ll a[], ll suff[], ll xr, ll&n)
{
  if(idx==n)
  {
    if(leave==0) ans=max(ans,xr);
    return;
  }
  if(leave==n-idx) solve(n,0,a,suff,xr,n);
  else if(leave>0) solve(idx+1,leave-1,a,suff,xr,n);
  if(leave==0) solve(n,0,a,suff,xr^suff[idx],n);
  else if(leave<n-idx) solve(idx+1,leave,a,suff,a[idx]^xr,n);
  
}

int main()
{
  IOS;
  ll t=1;
  for(int i=0;i<t;i++)
  {
     ll n,k; cin>>n>>k;
     ll a[n],suff[n];
     for(int i=0;i<n;i++) cin>>a[i];
     suff[n-1]=a[n-1];
     for(int i=n-2;i>=0;i--) suff[i]=suff[i+1]^a[i];
     solve(0,n-k,a,suff,0,n);
     cout<<ans<<endl;
  }
}
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

// Try to construct by the Logic below and u can easily understand what i mean !!

// Logic :

// The Main Observation lies the same i.e, to maintain the sum as (1+2.....+n) for both daigonals 
// But I couln't Come up with it !!
// So I Tried to make the sum of both diagonals to satisfy 2*(1+2+3...+n) 
// Every two adjacent rows combined and two adjacent columns combined we should satisfy the sum !!
// Now i observed that sum of every i and (n+1-i) is n+1 and there are n/2 pairs here as sum is ((n)*(n+1))/2
// So i try to keep 1 and n+1-i in every row (you can construct it by keeping in the column also)
// Now every row looks like 
// i n+1-i i n+1-i........ 
// And i will be increasing for each row  
// Now In this constuction diagonals will also be maintained !!

// for n=6

// 1 6 1 6 1 6 
// 2 5 2 5 2 5 
// 3 4 3 4 3 4 
// 4 3 4 3 4 3 
// 5 2 5 2 5 2 
// 6 1 6 1 6 1 

int main()
{
  IOS;
  ll t; cin>>t;
  for(int i=0;i<t;i++)
  {
    ll n; cin>>n;
    ll start=1; ll var;
    for(int i=0;i<n;i++)
    {
      var=start; start++;
      for(int j=0;j<n;j++)
      {
        if(j%2) cout<<n+1-var<<" ";
        else cout<<var<<" ";
      }
      cout<<endl;
    }
  }
}

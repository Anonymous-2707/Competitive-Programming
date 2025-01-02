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

// This is a construction problem and there can be many solutions and better ways to do it !!
// But I believe that there will be a Important Observation out of which we can construct the entire solution !!

// Observation !!

// As every adjacent rows sum and every adjacent columns sum should be same and should be equal to S1+S2;
// So I try to keep S1 and S2 as (1+2+3+....+n).
// So from this, think in the perspective of building rows,every row should consists of (1,2,3,....,n) and also every column should consists of (1,2,3......,n);
// So to construct a grid by maintaining this i tried to make rows in a cyclic fashion starting from 1 to n;
// By doing this for rows,coloums will be automatically taken care !!

// for n=5

// 1 2 3 4 5 
// 2 3 4 5 1
// 3 4 5 1 2 
// 4 5 1 2 3
// 5 1 2 3 4 

// Now we are confident about the rows sum and columns sum as we cyclically maintained it's sum as (1+2+3+....n) in every row and column !!
// Now one diagonal is (1+2+3...+n);
// But another diagonal is (n,n,n,n,n) so to make it's sum as (1+2+3+....+n);
// We try to swap n in every row with (n+1)/2; 
// Why because our main goal is to keep sum as(1+2+3+...+n)=((n)*(n+1))/2 
// Now there are n positions in the diagonal so lets try to put (n+1)/2 in all of them to maintain the sum as sum is ((n)*(n+1))/2 !!
// So let's swap n with (n+1)/2 so both the diagonals will be perfect in maintaining the sum !!
// Every row and column will have (1,2,...,n) !!
// As every rows n is exchanged with (n+1)/2 so n's place will be occupied with (n+1)/2 and viceversa, but sum will be retained !!

// so by using this property we can construct it !!

// ans for n=5;

// 1 2 5 4 3 
// 2 5 4 3 1
// 5 4 3 1 2 
// 4 3 1 2 5
// 3 1 2 5 4 


int main()
{
  IOS;
  ll t; cin>>t;
  for(int i=0;i<t;i++)
  {
    ll n; cin>>n;
    ll a[n][n];
    ll start=1; ll var;
    for(int i=0;i<n;i++)
    { 
      var=start; start++;
      for(int j=0;j<n;j++)
      {
         a[i][j]=var; var++;
         if(a[i][j]>n) a[i][j]%=n;
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(a[i][j]==(n+1)/2) a[i][j]=n;
        else if(a[i][j]==n) a[i][j]=(n+1)/2;
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
      cout<<endl;
    }
  }
}

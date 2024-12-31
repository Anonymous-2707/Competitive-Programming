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

// Here as k is very small we can think of some approach.
// To get an optimal answer definitely we need to explore all the possibilities.
// So it's a Problem of Dynamic Programming !!

// So we can think of an easy state as dp[idx1][idx2] represents minimum number of operations needed to make both the strings equal !!
// But this Doesn't fit the time complexity !!

// Observation :
//  Here if abs(idx1-idx2)>k which means that already greater than k operations are made so we can return a large number as this is not needed !!
//  So as abs(idx1-idx2)<=k so we can write dp state as dp[idx1][sdif];(Instead of storing idx2 we try to store the diffrence between idx1 and idx2+k) !!
//  sdif means translated difference between (idx1-idx2)
//  sdif=k+idx1-idx2; as idx1-idx2 can be negative and can't be stored in a vector as index so we are translating it by k 
//  we can get the exact difference by substracting it by k dif=sdif-k; 

// If they are equal s[idx],t[idx+dif] then no problem we just move 
// Else we explore all the three possibilities of Insert,replace,delete and then try to get minimum out of it.
// if any one reaches it's end then we can return length of the remaining untraversed length of the string

// If minimum length to make them equal is less than or equal to k then YES 
// Else NO.

ll solve(ll idx, ll sdif, string &s, string&t, ll&k, vector<vector<ll>>&dp)
{
  ll sz1=s.size(); ll sz2=t.size();
  ll dif=sdif-k; ll ans=INT_MAX;
  if(abs(dif)>k) return INT_MAX;
  if(idx==sz1) return sz2-dif-idx;
  if(idx+dif==sz2) return sz1-idx;
  if(dp[idx][sdif]!=-1) return dp[idx][sdif];
  if(s[idx]==t[idx+dif]) ans=min(ans,solve(idx+1,sdif,s,t,k,dp));
  else
  {
    ans=min(ans,1+solve(idx+1,sdif,s,t,k,dp));
    ans=min(ans,1+solve(idx,sdif+1,s,t,k,dp));
    ans=min(ans,1+solve(idx+1,sdif-1,s,t,k,dp));
  }
  return dp[idx][sdif]=ans;
} 

int main()
{
  IOS;
  ll k; cin>>k;
  string s,t; cin>>s>>t;
  ll sz1=s.size(); ll sz2=t.size();
  vector<vector<ll>> dp(sz1+1,vector<ll>((2*k)+1));
  for(int i=0;i<sz1+1;i++)
  {
    for(int j=0;j<(2*k)+1;j++) dp[i][j]=-1;
  }
  if(solve(0,k,s,t,k,dp)<=k) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}



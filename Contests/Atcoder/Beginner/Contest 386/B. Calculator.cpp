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

// Our Available options are 00,0,1,2,3,4,5,6,7,8,9.
// For any option other than zero we need to press once to get it on the calculator screen.
// In case of 0, for 2 consecutive zeros we can press only once and we will utilize it to minimize number of presses !! 
// If there are x consecutive zeros we press only x/2 times !!

int main()
{
  IOS;
  string s; cin>>s;
  ll ans=s.size(); ll sz=s.size();
  for(int i=0;i<sz-1;i++)
  {
    if(s[i]==s[i+1] && s[i]=='0') ans--,i++;
  }
  cout<<ans<<endl;
}
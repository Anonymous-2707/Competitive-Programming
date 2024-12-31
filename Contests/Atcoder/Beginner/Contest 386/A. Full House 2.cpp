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

// Our goal is to have a total of 5 cards---> 3 of one kind and 2 of other
// We have 4 of it which mean that there is 1 missing card so there are 2 possibilities after removal.  
// 1.(2 of one kind and 2 of other) 
// 2.(3 of one kind and 1 of other)
// Which means that out of given numbers there should be exactly 2 distint numbers if not then it won't fall into either of these 2 possibilities !!
// So if there are 2 distint numbers it's YES else NO

int main()
{
  IOS;
  ll a,b,c,d; cin>>a>>b>>c>>d;
  map<ll,ll> freq;
  freq[a]++; freq[b]++; freq[c]++; freq[d]++;
  if(freq.size()!=2) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}

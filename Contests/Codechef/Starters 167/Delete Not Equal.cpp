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

// let's think of the possibilities.
// For Example let's assume a string like ..........00011....... or ...............11110000................
// Now where there is a change from 0 to 1 or 1 to 0, consider that 0 and delete the continuous segment of 1's until they become just one 1.
// Now use that 1 and then delete continuous segment of 0's until they become just one 0.
// So the string becomes ...........01.............. or .................10..................
// Now do it for every segment and make string look like an alternative sequence of 0 and 1.
// Now for any alternative sequence 010101010 or 1010101010 as the consecutive elements are different we can delete every element and only one element will be left !!
// So ans will be 1 !!

// Edge case : 
// If all the elements are just 1 or 0 then there is nothing to delete so ans will be length of the string !!

int main()
{
  IOS;
  ll t; cin>>t;
  for(int i=0;i<t;i++)
  {
    ll n; cin>>n;
    string s; cin>>s;
    ll cnt=1;
    for(int i=0;i<n-1;i++)
    {
      if(s[i]==s[i+1]) cnt++;
      else break;
    }
    if(cnt==n) cout<<n<<endl;
    else cout<<1<<endl;
  }
}

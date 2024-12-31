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

// In this easy version k=1 which mean we have only 1 excuse to move forward even though they are not same !!
// If the absolute difference between lengths of the strings is greater than 1 then it's Definitely NO as number of excuses will be greater than 1.
// If both the strings have same length then we can iterate directly and count where both charecters differ 
// If that count is greater than 1 then NO.
// Now both strings differ by length of 1 and it doesn't matter weather we make S as T or T as S, so lets swap and make S as the smaller string and T as larger one !!
// Now Iterate until u find a place where both the charecters differ and at that position consider it as an excuse and keep the position of i the same by doing i-- (as it will be i++ again) and iterate until the end of any of the strings
// If Excuses are greater than 1 then NO.
// If there is no possibility of NO then it's YES. 

int main()
{
  IOS;
  ll k; cin>>k;
  string s,t; cin>>s>>t;
  ll sz1=s.size(); ll sz2=t.size();
  if(abs(sz1-sz2)>1) cout<<"No"<<endl;
  else
  {
    if(sz1==sz2)
    {
      ll excuse=0; ll ptr=0;
      for(int i=0;i<sz1;i++)
      {
        if(s[i]!=t[ptr]) excuse++;
        ptr++;
      }
      if(excuse>k) cout<<"No"<<endl;
      else cout<<"Yes"<<endl;
    }
    else
    {
      if(sz1>sz2) swap(s,t),swap(sz1,sz2);
      ll excuse=0; ll ptr=0;
      for(int i=0;i<sz1;i++)
      {
        if(ptr==sz2) break;
        if(s[i]!=t[ptr]) excuse++,i--;
        ptr++;
      }
      if(excuse>k) cout<<"No"<<endl;
      else cout<<"Yes"<<endl;
    }
  }
}
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

// Most Important thing to solve this Qn is to take a pen and paper and draw the test cases !!
// Analyze the problem row wise that is try to think upto which column every row can be coloured black ??

// There are 2 important observations to make !!

// 1.If any particular (x,y) is coloured black then from the properties mentioned in the question first y blocks in the xth row should be coloured and first x blocks in the yth column should be coloured
//   So from the above point, as first y blocks in the xth row are coloured which means first x blocks in first y coloumns should be coloured as this block is coloured !!
//   Which means if we consider top left point as (1,1) then if (x,y) is coloured black then each and every block enclosed by the rectangle (1,1),(1,y),(x,1),(x,y) will be black

// 2.From the above point now if you start observing the question as we go through the rows, number of coloums coloured black will always decrease !!
//   Lets say there are 2 rows r1,r2 and number of black blocks be c1,c2 respectively with r1<r2,c1<c2  
//   Now draw this situation as c2>c1 the rectangle (1,1),(1,c1),(r1,1),(r1,c1) will lie in the rectangle (1,1),(1,c2),(r2,1),(r2,c2)  
//   so for r1 also c2 blocks will be coloured !! 

// Now lets push all blacks in a vector as (y,x) and sort them in reverse order
// Iterate it with the rw variable starting with 0 to find the upperbound for a particular number of columns coloured and then updating it to find the next upperbound (for loop iterated on blacks in the code) !! 

// Iterate through the whites vector 
// So for a particular row we will do a lower bound for it to find in which range does this row falls in and then see the number of black blocks in that range 
// For atleast one of the whites if it is greater than the column in the white then it's a NO as it is coloured black 
// Else YES

int main()
{
  IOS;
  ll t=1;
  for(int i=0;i<t;i++)
  {
     ll n,m; cin>>n>>m;
     vector<pair<ll,ll>> blacks,whites;
     for(int i=0;i<m;i++)
     {
        ll x,y; cin>>x>>y;
        char ch; cin>>ch;
        if(ch=='B') blacks.pb({y,x});
        else whites.pb({x,y});
     }
     sort(blacks.begin(),blacks.end(),greater<>());
     ll rw=0;
     vector<pair<ll,ll>> v;
     for(int i=0;i<blacks.size();i++)
     {
       ll x=blacks[i].second; ll y=blacks[i].first;
       if(x>rw) v.pb({x,y}),rw=x;
     }
     sort(v.begin(),v.end());
     ll flg=1;
     for(int i=0;i<whites.size();i++)
     {
       pair<ll,ll> p=make_pair(whites[i].first,0);
       auto it=lower_bound(v.begin(),v.end(),p);
       if(it!=v.end() && it->second>=whites[i].second) flg=0; 
     }
     if(flg) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
  }
}
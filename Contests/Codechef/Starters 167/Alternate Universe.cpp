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

// Now Let's think of what can we do ??
// Let's proceed with a linear search over the answer, but it definitely gives TLE !!
// So We should do binary search but is there any monotonicity ??
// Let's assume x as answer then can we definitely say x+1 can be an answer ??
// No We can't i'll give you an example 
// 2
// 0 35
// 43 0
// Here 0 is an answer but 1 isn't !!
// So Let's Modify out approach which creates Monotonicity and then apply binary search on it !!
// Our function is, for any rating <=x is there any solution ??
// So let say answer is r then for all ratings>=r this is true and for all ratings<r it is false 

// Now apply the binary search by taling low as 0 and high as n
// In the check function we have a mid, which means that every rating from 0 to mid is possible
// So let's introduce a variable called upperbound which means that every rating from 0 to upper bound is possible at that particular situation.
// Now if upperbound<a[i] then we can increase our upperbound to upperbound+b[i];
// If upperbound>a[i] then,as we have all the possibilities from 0 to upperbound in which a[i] is present, so consider the rating value as a[i], now we have the chance to increase the upperbound to (a[i]+b[i]);
// So we always have certain previlige to increase our upperbound to max(upperbound,min(a[i],upperbound)+b[i]),and it will be decreased by 1 at every stage !!
// Continue the same process through out the loop !!
// Now at any stage if upperbound<0  return 0, else return 1;

// By doing binary search we can get the answer !!

ll check(ll mid, ll a[], ll b[], ll &n)
{
   ll upper_bound=mid;
   for(ll i=0;i<n;i++)
   {
    upper_bound=max(upper_bound,min(a[i],upper_bound)+b[i]); 
    upper_bound--;
    if(upper_bound<0) return 0;
   }
   return 1;
}

int main()
{
  IOS;
  ll t; cin>>t;
  for(int i=0;i<t;i++)
  {
    ll n; cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    ll low=0; ll high=n;
    while(low<high)
    {
       ll mid=(high+low)/2;
       if(check(mid,a,b,n)) high=mid;
       else low=mid+1;
       if(high-low<=1) break;
    }
    if(check(low,a,b,n)) cout<<low<<endl;
    else cout<<high<<endl;
  }
}

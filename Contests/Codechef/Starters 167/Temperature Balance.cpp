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

// Most Important thing in this Question is understanding why it works !!
// So be with me i'll make sure you understand why it works !!

// Let's treat this as energy and it flows from high temperature to low temperature 
// Now we know that sum of a1+a2+.....+an=0.
// Now try to analyze how much energy needs to be flown at a particular partition
// Lets declare energy,ans as variables and initialize them as 0;
// Now as we go through the array add a[i] to energy
// If energy is greater than 0 then right is lacking energy and this is the minimum amount of energy that must be flown to the right side !!
// If energy is less than 0 then left side is lacking energy and this is the minimum amount of energy that must be flown to the left side !!
// So abs(energy) is the minimum amount of energy that needs to be flown through this partition so add this to ans !!

// Now i claim that this is the answer !!
// As we taken care that at every partition, flow can be in any direction but we added the minimum amount of energy need to cool the system.

// But I know you may have a small doubt, don't worry i'll make you understand how to generste this minimum answer !!

// Proof of Answer :

// Maintain a set<pair<ll,ll>>
// Iterate through array a and insert {energy,i} where energy is abs(prefix sum) upto index i, i can also be used to name the partition !!
// Now Greedily try to make the transfer at the partition where there is more demand of energy, that is at the partition where the energy flow requirement is high.
// We can find it as the last pair of the set so try to extract it and erase and now make the transfer in the required direction and decrease the energy by 1 and if it's not 0 then insert back
// Try to repeat the process until the set becomes empty !!

// This is the perfect way to Analyze how the flow will be in order to make all of them 0 in the minimum operations possible !!  

// Try to write some test cases and apply it you will clearly get the idea of how to achieve in minimum steps !!


int main()
{
  IOS;
  ll t; cin>>t;
  for(int i=0;i<t;i++)
  {
    ll n; cin>>n;
    ll a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0; ll energy=0;
    for(int i=0;i<n;i++) energy+=a[i],ans+=abs(energy);
    cout<<ans<<endl;
  }
}

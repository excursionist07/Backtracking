#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

void TowerOfHanoi(ll n,ll from,ll to,ll aux)
{
 if(n==1)
 {
  cout<<"move disk 1 from rod"<<" "<<from<<" "<<"to rod"<<" "<<to<<endl;
  return;
 }
 TowerOfHanoi(n-1,from,aux,to);
 cout<<"move disk"<<" "<<n<<" "<<"from rod"<<" "<<from<<" "<<"to rod"<<" "<<to<<endl;
 TowerOfHanoi(n-1,aux,to,from);
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  TowerOfHanoi(n,1,3,2);
  cout<<pow(2,n)-1<<endl;
 }
 return 0;
}

// Josephus problem

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

ll josephus(ll n,ll k)
{
 if(n==1)
    return 1;
 return (josephus(n-1,k)+k-1)%n+1;
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
 ll n,k;
 cin>>n>>k;
 cout<<josephus(n,k)<<endl;
 }
 return 0;
}


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

ll dir[][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};

// Recursion

/*ll CountItUtil(char keypad[][3],ll x,ll y,ll n)
{
 if(n<=0)
    return 0;
 if(n==1)
    return 1;
 ll cnt1=0;
 for(ll i=0;i<5;i++)
 {
  ll xx=x+dir[i][0];
  ll yy=y+dir[i][1];
  if(xx>=0 && xx<4 && yy>=0 && yy<3 && keypad[xx][yy]!='#' && keypad[xx][yy]!='*')
  {
    cnt1+=CountItUtil(keypad,xx,yy,n-1);
  }
 }
 return cnt1;
}
ll CountIt(char keypad[][3],ll n)
{
 if(n<=0)
    return 0;
 if(n==1)
    return 10;
 ll cnt=0;
 for(ll i=0;i<4;i++)
 {
  for(ll j=0;j<3;j++)
  {
   if(keypad[i][j]!='#' && keypad[i][j]!='*')
   {
    cnt+=CountItUtil(keypad,i,j,n);
   }
  }
 }
 return cnt;
}*/


// D.P

ll CountIt1(char keypad[][3],ll n)
{
 if(n<=0)
    return 0;
 if(n==1)
    return 10;
 ll dp[10][n+1];
 for(ll i=0;i<10;i++)
 {
  dp[i][0]=0;
  dp[i][1]=1;
 }
 for(ll len=2;len<=n;len++)
 {
  for(ll i=0;i<4;i++)
  {
   for(ll j=0;j<3;j++)
   {
    if(keypad[i][j]!='#' && keypad[i][j]!='*')
    {
    ll num=keypad[i][j]-'0';
    dp[num][len]=0;
    for(ll p=0;p<5;p++)
    {
     ll xx=i+dir[p][0];
     ll yy=j+dir[p][1];
     if(xx>=0 && xx<4 && yy>=0 && yy<3 && keypad[xx][yy]!='#' && keypad[xx][yy]!='*')
     {
      ll num1=keypad[xx][yy]-'0';
      dp[num][len]+=dp[num1][len-1];
     }
    }
    }
   }
  }
 }
 ll cnt=0;
 for(ll i=0;i<=9;i++)
    cnt+=dp[i][n];
 return cnt;
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
  char keypad[][3]=
  {
     {'1','2','3'},
     {'4','5','6'},
     {'7','8','9'},
     {'*','0','#'}
  };
  //cout<<CountIt(keypad,n)<<endl;
   cout<<CountIt1(keypad,n)<<endl;


 }
 return 0;
}

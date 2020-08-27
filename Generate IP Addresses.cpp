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

bool is_valid(string ip)
{
 vector<string>ips;
 string pp="";
 f(ip.length())
 {
  if(ip[i]=='.')
  {
    ips.pb(pp);
    pp="";
  }
  else
    pp=pp+ip[i];

 }

 ips.pb(pp);

 f(ips.size())
 {
  if(ips[i].length()>3 || stoll(ips[i])>255)
    return 0;
  if(ips[i].length()>1 && ips[i][0]=='0')
    return 0;
 }
 return 1;
}

void convert(string IP)
{
 string check=IP;
 ll len=IP.length();
 vector<string>ans;
 if(len>12 || len<4)
 {
   cout<<"Not Valid IP Address"<<endl;
   return;
 }
 for(ll i=1;i<len-2;i++)
 {
  for(ll j=i+1;j<len-1;j++)
  {
   for(ll k=j+1;k<len;k++)
   {
    check=check.substr(0,k)+"."+check.substr(k,len-k);
    check=check.substr(0,j)+"."+check.substr(j,len-j+1);
    check=check.substr(0,i)+"."+check.substr(i,len-i+2);
    if(is_valid(check))
        ans.pb(check);
    check=IP;
   }
  }
 }
 ll zz=ans.size();
 cout<<"Total"<<"="<<zz<<endl;
 f(zz)
  cout<<ans[i]<<endl;


}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str;
  cin>>str;
  convert(str);

 }
 return 0;

}

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=26;

struct Node
{
  Node* children[N];
  bool isEnd;
};

Node* getNode()
{
 Node* temp=new Node();
 temp->isEnd=false;
 rep(i,0,N)
  temp->children[i]=NULL;
 return temp;
}

void Insert(Node* root,string str)//O(l*n) where l is avg. length of string
{
 Node* temp=root;
 rep(i,0,str.length())
 {
  ll idx=str[i]-'a';
  if(!temp->children[idx])
    temp->children[idx]=getNode();
  temp=temp->children[idx];
 }
 temp->isEnd=true;
}

bool Search(Node* root,string str)//O(M) where M is the max length of string
{
 Node* temp=root;
 rep(i,0,str.length())
 {
  ll idx=str[i]-'a';
  if(!temp->children[idx])
    return false;
  temp=temp->children[idx];
 }
 return temp->isEnd;
}

bool startsWith(string str)
{
 Node* temp=root;
 rep(i,0,str.length())
 {
  ll idx=str[i]-'a';
  if(!temp->children[idx])
    return false;
  temp=temp->children[idx];
 }
 return true;
}

int main()
{
 hs;
 ll n;
 cin>>n;
 string str[n];
 rep(i,0,n)
  cin>>str[i];
 Node* root=getNode();
 rep(i,0,n)
  Insert(root,str[i]);
 ll q;
 cin>>q;
 while(q--)
 {
  string ss;
  cin>>ss;
  if(Search(root,ss))
    cout<<"found";
  else
    cout<<"Not found";
  cout<<"\n";

 }
 return 0;
}

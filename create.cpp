#include<bits/stdc++.h>
#define up(j,k,i) for(i=j;i<k;i++)
#define down(j,k,i) for(i=j;i>k;i--)
#define M 1000000007
#define pp(n) printf("%lld\n",ll(n))
#define ps(n) printf("%lld ",ll(n))
#define pd(x,y) printf("%lld %lld\n",ll(x),ll(y))
#define is(n) scanf("%lld",&n)
#define max(x,y) max(ll(x),ll(y))
#define min(x,y) min(ll(x),ll(y))
#define inf LLONG_MAX
#define id(n,m) scanf("%lld%lld",&n,&m)
#define it(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define ss(s) scanf("%s",s)
#define cool 0
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pll pair<ll,ll> 
#define db cout<<"######\n"
#define null(a) memset(a,0,sizeof(a))
#define neg(a) memset(a,255,sizeof(a))
typedef long double ld;
typedef long long int ll;
using namespace std;
ll i,j,k,z,t,n,m,sum,ans,x,y,maxm=0,minm=inf; bool flag;
int main()
{
	freopen("NFA.txt","w",stdout);
	freopen("keywords.txt","r",stdin);
	
	is(n);
	
	string s[n];
	
	vector<ll> sta,en;
	ll cur=0;
	
	map<char,vector<ll> > sta0;
	
	vector<pair<pll,ll>> tra;
	
	for(char c='a';c<='z';c++)
	sta0[c].pb(0);
	
	up(0,n,i)
	{
		cin>>s[i];
		
		sta0[s[i][0]].pb(++cur);
		
		up(1,s[i].size(),j)
		tra.pb({{cur,s[i][j]-'a'+1},++cur});
		
		en.pb(cur);
			
	}
	
	pd(cur+1,26);
	
	ps(n);
	
	for(auto c:en)
	ps(c);	
	
	cout<<endl;
	
	pp(tra.size()+sta0.size());
	
	
	for(auto c:sta0)
	{cout<<"0 "<<int(c.F)-int('a')+1<<" "; ps(c.S.size()); for(auto d:c.S) ps(d); cout<<endl;}
	
	
	for(auto c:tra)
	cout<<c.F.F<<" "<<c.F.S<<" "<<"1 "<<c.S<<endl;
	
	
	
	
	
	  		
}
	

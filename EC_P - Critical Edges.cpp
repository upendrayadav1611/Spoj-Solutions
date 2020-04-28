#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double

#define mod 1000000007
#define EULER 2.7182818284
#define INF 1000000000

#define pb push_back
#define IT iterator
#define PQ priority_queue

#define fi first
#define se second
#define maxe max_element
#define mine min_element
#define er erase

#define all(x) x.begin(), x.end()
#define srt(v) sort(all(v))
#define rsrt(v) \
    srt(v);     \
    reverse(all(v))
#define uni(x) x.erase(unique(all(x)), x.end())
#define sqr(x) ((x)*(x))
#define mem(v,i) memset(v,i,sizeof(v)) // v is array. To set all elements to 0 or -1 only. mem(arr,0);

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORl(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORN(i,n) for(int i=(0);i<(n);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)

using namespace std;
vector<ll>vec[100005];
ll in[100000];
ll low[100000];
bool vis[100000];
vector<pair<ll,ll>>vp;
ll timer,ans;
ll min(ll a, ll b)
{
	if(a<b)
	return a;
	return b;
}
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.fi!=b.fi)
    return a.fi<b.fi;
    return a.se<b.se;
}
void dfs(ll node,ll par)
{
	vis[node]=true;
	in[node]=low[node]=timer;
	timer++;
	for(ll child:vec[node])
	{
		if(child==par)
		continue;
		if(vis[child]==true)
		{
			low[node]=min(low[node],in[child]);
		}
		else
		{
			dfs(child,node);
			if(low[child]>in[node])
			{
				ans++;
				if(min(node,child)==node)
				vp.pb({node,child});
				else
				vp.pb({child,node});
			}
			low[node]=min(low[node],low[child]);
		}
	}
}


int main()
{
    fast
   	ll t,n,m,x,y,i;
   	cin>>t;
   	for(i=1;i<=t;i++)
   	{
   		cin>>n>>m;
   		vp.clear();
   		ans=0,timer=0;
   		for(ll j=1;j<=n;j++)
   		{
   			vec[j].clear();
   			//in[i]=0;
   			//low[i]=0;
   			vis[j]=false;
   		}
   		while(m--)
   		{
   			cin>>x>>y;
   			vec[x].pb(y);
   			vec[y].pb(x);
   		}
   		dfs(1,-1);
   		sort(vp.begin(),vp.end(),comp);
   		if(ans==0)
   		{   
   		    cout<<"Caso #"<<i<<"\n";
   		    cout<<"Sin bloqueos"<<"\n";
   		}
   		else
   		{
   			cout<<"Caso #"<<i<<"\n";
   			cout<<ans<<"\n";
   			for(ll j=0;j<vp.size();j++)
   			{
   				cout<<vp[j].fi<<" "<<vp[j].se<<"\n";
   			}
   		}
   		
   	}
    return 0;
}
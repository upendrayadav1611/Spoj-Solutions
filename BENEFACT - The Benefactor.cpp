#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>> vec[50005];
ll dis[50005];
bool vis[50005];
void bfs(ll src)
{
	dis[src]=0;
	queue<ll>q;
	q.push(src);
	while(!q.empty())
	{
		ll p=q.front();
		q.pop();
		if(vis[p])
		continue;
		vis[p]=true;
		for(ll i=0;i<vec[p].size();i++)
		{
			ll child=vec[p][i].first;
			if(!vis[child])
			{
			    dis[child]=dis[p]+vec[p][i].second;
			    q.push(child);
			}
		}
	}
}
int main()
{
	ll t,n,k,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		k=n-1;
		for(i=0;i<=n;i++)
		{
			vec[i].clear();
			dis[i]=0;
			vis[i]=false;
		}
		ll x,y,w;
		while(k--)
		{
			cin>>x>>y>>w;
			vec[x].push_back({y,w});
			vec[y].push_back({x,w});
		}
		bfs(1);
		ll mx=0;
		k=0;
		for(i=1;i<=n;i++)
		{
			if(dis[i]>mx)
			{
				mx=dis[i];
				k=i;
			}
		}
		//cout<<mx<<"\n";
		for(i=0;i<=n;i++)
		{
			dis[i]=0;
			vis[i]=false;
		}
		bfs(k);
		cout<<*max_element(dis,dis+n)<<"\n";
		
	}
}
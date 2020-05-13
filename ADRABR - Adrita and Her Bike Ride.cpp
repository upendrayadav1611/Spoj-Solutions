#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define INF 1e18
vector<pair<ll,ll>>vec[100005];
ll dis[100005];
//bool vis[100005];
void dijkstra(ll src)
{
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
	q.push({src,0});
	dis[src]=0;
	while(!q.empty())
	{
		ll cur=q.top().first;
		ll cur_dis=q.top().second;
		q.pop();
		for(pair<ll,ll>edge:vec[cur])
		{
			if((cur_dis+edge.second)<dis[edge.first])
			{
				dis[edge.first]=cur_dis+edge.second;
				q.push({edge.first,dis[edge.first]});
			}
		}
	}
	
}
int main()
{
	ll t,n,m,s,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>s>>d;
		ll i,x,y,w;
		for(i=0;i<=n;i++)
		{
			vec[i].clear();
			dis[i]=INF;
			//vis[i]=false;
		}
		while(m--)
		{
			cin>>x>>y>>w;
			vec[x].push_back({y,12+w});
			vec[y].push_back({x,12+w});
		}
		dijkstra(s);
		cout<<dis[d]<<"\n";
		
		
	}
}
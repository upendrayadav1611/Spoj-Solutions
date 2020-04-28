#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>>vec[100004];
vector<ll>dis(100004,INT_MAX);
void dijkstra(ll src)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        ll curr=pq.top().second;
        ll curr_dis=pq.top().first;
        pq.pop();
        for(pair<ll,ll>edge:vec[curr])
        {
            if(curr_dis+edge.second<dis[edge.first])
            {
                dis[edge.first]=curr_dis+edge.second;
                pq.push({dis[edge.first],edge.first});
            }
        }
    }
}
int main()
{
    ll n,m,u,v,w,s,d,t;
    cin>>t;
    while(t--)
    {
	    cin>>n>>m>>s>>d;
	    for(int i=1;i<=n;i++)
	    dis[i]=INT_MAX;
	    while(m--)
	    {
	        cin>>u>>v>>w;
	        vec[u].push_back({v,w});
	        vec[v].push_back({u,w});
	    }
	    
	    dijkstra(s);
	    if(dis[d]==INT_MAX)
	    cout<<"NONE"<<"\n";
	    else
	    cout<<dis[d]<<"\n";
    }
}
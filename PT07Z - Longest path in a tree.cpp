#include<bits/stdc++.h>
using namespace std;
vector<int> vec[10005];
int vis[10005];
int maxd,maxnode;
void dfs(int v,int d)
{
	vis[v]=1;
	if(d>maxd)
	{
	    maxd=d;
	    maxnode=v;
	}

	for(int i=0;i<vec[v].size();i++)
	{
		int child=vec[v][i];
		if(vis[child]==0)
		{
			dfs(child,d+1);
		}
	}
}
int main()
{
	int n,u,v,t;
	cin>>n;
	t=n-1;
	for(int i=0;i<=n;i++)
	{
	    vis[i]=0;
	    vec[i].clear();
	}
	while(t--)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	maxd=-1;
	dfs(1,0);
	maxd=-1;
	for(int i=0;i<=n;i++)
	{
	    vis[i]=0;
	}
	dfs(maxnode,0);
	cout<<maxd<<endl;
	
	
	
	
}
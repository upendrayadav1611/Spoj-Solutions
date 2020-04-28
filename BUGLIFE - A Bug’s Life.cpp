#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000001];
int vis[1000001];
int col[1000001];
int dfs(int v,int c)
{
	vis[v]=1;
	col[v]=c;
	for(int i=0;i<vec[v].size();i++)
	{
		int child=vec[v][i];
		if(vis[child]==0)
		{
			if(dfs(child,c^1)==0)
			return 0;
		}
		else 
		{
			if(col[v]==col[child])
			return 0;
		}
	}
	return 1;
}
int main()
{
	int t,n,m,u,v,res;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m;
		for(int j=0;j<1000001;j++)
		{
		    vec[j].clear();
		    vis[j]=0;
		    col[j]=0;
		}
		while(m--)
		{
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for(int j=1;j<=n;j++)
		{
		    if(vis[j]==0)
		    {
		        res=dfs(j,1);
		        if(res==0)
		        break;
		    }
		}
		if(res)
		{
			cout<<"Scenario #"<<i<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}
		else
		{
			cout<<"Scenario #"<<i<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
	}
}
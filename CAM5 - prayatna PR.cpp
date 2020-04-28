#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005];
int vis[100005];
void dfs(int v)
{
	vis[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int child=vec[v][i];
		if(!vis[child])
		dfs(child);
	}
}
int main()
{
	int t,n,i,e;
	cin>>t;
	while(t--)
	{
		cin>>n>>e;
		int a,b;
		for(i=0;i<n;i++)
		{
		    vec[i].clear();
		    vis[i]=0;
		}
		while(e--)
		{
		    cin>>a>>b;
		    vec[a].push_back(b);
		    vec[b].push_back(a);
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				ans++;
				dfs(i);
			}
		}
		cout<<ans<<endl;
	}
}
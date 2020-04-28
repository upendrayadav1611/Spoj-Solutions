#include <bits/stdc++.h>
using namespace std;
vector<int> vec[10001];
int vis[10001];
void dfs(int v)
{
	vis[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int child=vec[v][i];
		if(vis[child]==0)
		dfs(child);
	}
}
int main() {
	// your code goes here
	int n,m,u,v,k=0,t;
	cin>>n>>m;
	t=m;
	while(m--)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			
			dfs(i);
			k++;
		}
	}
	if(k==1&&n-1==t)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
bool vis[10001];
int cnt=0;
void dfs(int v)
{
	vis[v]=true;
	cnt++;
	for(int i=0;i<vec[v].size();i++)
	{
		int child=vec[v][i];
		if(!vis[child])
		dfs(child);
	}
}
int main()
{
	int n,m,i,x,y;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
	}
	int mx=0;
	for(i=1;i<n;i++)
	{	
		cnt=0;
		dfs(i);
		if(cnt>mx)
		mx=cnt;
		for(int j=1;j<=n;j++)
		vis[j]=false;
	}
	printf("%d\n",mx);
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool vis[1000005];
ll dis[1000005];
ll u,d,f,g;
bool isvalid(ll k)
{
	return k>=1&&k<=f;
}
void bfs(ll src)
{
	vis[src]=true;
	dis[src]=0;
	queue<int>q;
	q.push(src);
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(isvalid(curr-d)&&vis[curr-d]==false)
		{
			vis[curr-d]=true;
			dis[curr-d]=dis[curr]+1;
			q.push(curr-d);
		}
		if(isvalid(curr+u)&&vis[curr+u]==false)
		{
			vis[curr+u]=true;
			dis[curr+u]=dis[curr]+1;
			q.push(curr+u);
		}
		
	}
}
int main()
{
	ll s,i;
	cin>>f>>s>>g>>u>>d;
	for(i=1;i<=f;i++)
	{
		vis[i]=false;
		dis[i]=0;
	}
	bfs(s);
	if(vis[g]==false)
	cout<<"use the stairs"<<"\n";
	else
	cout<<dis[g]<<"\n";
	return 0;
	
}

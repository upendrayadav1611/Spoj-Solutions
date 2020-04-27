#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m;
ll par[100005],r[100005];
ll find(ll a)
{
	if(par[a]<0)
	return a;
	return par[a]=find(par[a]);
}
void merge(ll a,ll b)
{
	if(r[a]>r[b])
	{
		par[b]=a;
		r[a]+=r[b];
	}
	else
	{
		par[a]=b;
		r[b]+=r[a];
	}
}
int main()
{
	ll q;
	cin>>n>>m;
	cin>>q;
	for(ll i=1;i<=n;i++)
	{
		par[i]=-1;
		r[i]=1;
	}
	while(q--)
	{
		string s;
		ll x,y;
		cin>>s;
		if(s[0]=='S')
		{
			cin>>x;
			cout<<r[find(x)]<<"\n";
		}
		else if(s[0]=='A')
		{
			cin>>x>>y;
			x=find(x);
			y=find(y);
			if(r[x]+r[y]<=m)
			merge(x,y);
		}
		else
		{
			cin>>x>>y;
			if(find(x)==find(y))
			cout<<"Yes\n";
			else
			cout<<"No\n";
		}
	}
	return 0;
}
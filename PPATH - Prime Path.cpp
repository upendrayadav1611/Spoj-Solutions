#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> vec[100000];
vector<ll>prime;
bool vis[100000];
ll dis[100000];
bool isprime(ll a)
{
	for(ll i=2;i<=sqrt(a);i++)
	if(a%i==0)
	return false;
	return true;
}
void findprime()
{
	for(ll i=1000;i<=9999;i++)
	{
		if(isprime(i))
		prime.push_back(i);
	}
}
bool isvalid(ll a,ll b)
{
	ll cnt=0;
	while(a>0)
	{
		if(a%10!=b%10)
		cnt++;
		a=a/10;
		b=b/10;
	}
	if(cnt==1)
	return true;
	return false;
}
void makegraph()
{
	for(ll i=0;i<prime.size();i++)
	{
		for(ll j=i+1;j<prime.size();j++)
		{
			if(isvalid(prime[i],prime[j]))
			{
				vec[prime[i]].push_back(prime[j]);
				vec[prime[j]].push_back(prime[i]);
			}
		}
	}
}
void bfs(ll src)
{
	vis[src]=true;
	dis[src]=0;
	queue<ll>q;
	q.push(src);
	while(!q.empty())
	{
		ll curr=q.front();
		q.pop();
		for(ll i=0;i<vec[curr].size();i++)
		{
			ll child=vec[curr][i];
			if(vis[child]==false)
			{
				vis[child]=true;
				dis[child]=dis[curr]+1;
				q.push(child);
			}
		}
	}
	
}
int main()
{
	ll t,a,b;
	cin>>t;
	findprime();
	makegraph();
	while(t--)
	{
		cin>>a>>b;
		for(ll i=1000;i<=9999;i++)
		{
			dis[i]=-1;
			vis[i]=false;
		}
		bfs(a);
		if(dis[b]==-1)
		cout<<"Impossible"<<"\n";
		else
		cout<<dis[b]<<"\n";
	}
	
}
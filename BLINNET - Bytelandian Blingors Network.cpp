#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll par[10005];
ll r[10005];
struct edge{
    int a,b,w;
};
edge ar[10000000];
bool comp(edge a,edge b)
{
    return a.w<b.w;
}
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
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,i,k,c,a,b;
		string s;
		cin>>n;
		for(i=1;i<=n;i++)
        {
            par[i]=-1;
            r[i]=1;
        }
        ll p=0;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			cin>>m;
			while(m--)
			{
				cin>>k>>c;
				ar[p].a=i;
				ar[p].b=k;
				ar[p].w=c;
				p++;
			}
		}
		sort(ar,ar+p,comp);
		ll sum=0;
		for(i=0;i<p;i++)
	    {
	        a=find(ar[i].a);
	        b=find(ar[i].b);
	        if(a!=b)
	        {
	            sum=sum+ar[i].w;
	            merge(a,b);
	        }
	    }
	    cout<<sum<<"\n";
	}
}
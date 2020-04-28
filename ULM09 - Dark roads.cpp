#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll par[200005];
ll r[200005];
struct edge{
    int a,b,w;
};
edge ar[200005];
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
    ll n,m,i,a,b;
    //cin>>n>>m;
    while(scanf("%ld%ld",&n,&m),n!=0,m!=0)
    {
        for(i=0;i<n;i++)
        {
            par[i]=-1;
           	r[a]=1;
        }
        ll total=0;
        for(i=0;i<m;i++)
        {
        	cin>>ar[i].a>>ar[i].b>>ar[i].w;
        	total=total+ar[i].w;
        }
    
        sort(ar,ar+m,comp);
        ll sum=0;
        for(i=0;i<m;i++)
        {
            a=find(ar[i].a);
            b=find(ar[i].b);
            if(a!=b)
            {
                sum=sum+ar[i].w;
                merge(a,b);
            }
        }
        cout<<total-sum<<"\n";
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
vector<int>vec[10000];
int vis[10000],par[10000],level[10000];
void dfs(int v, int p)
{
    vis[v]=1;
    par[v]=p;
    for(int i=0;i<vec[v].size();i++)
    {
        int child=vec[v][i];
        if(vis[child]==0)
        {   
            level[child]=level[v]+1;
            dfs(child,v);
        }
    }
}
ll lca(ll a,ll b)
{
    ll d,k;
    if(level[a]>level[b])
    {
        d=level[a]-level[b];
    }
    else
    {
        d=level[b]-level[a];
    }
    while(level[a]!=level[b])
    {
        if(level[a]>level[b])
        {
            a=par[a];
        }
        else
        {
            b=par[b];
        }
    }
    if(a==b)
    return a;
    while(par[a]!=par[b])
    {
        a=par[a];
        b=par[b];
    }
    return par[a];
}
int main()
{
    ll n,m,i,u,v,t,q;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        for(ll j=0;j<=n;j++)
        {
            vec[j].clear();
            vis[j]=0;
           
            level[j]=0;
            par[j]=0;
        }
        for(ll j=1;j<=n;j++)
        {
            cin>>m;
            while(m--)
            {
                cin>>u;
                vec[u].push_back(j);
                vec[j].push_back(u);
            }
        }
        level[1]=0;
        dfs(1,-1);
        cin>>q;
        cout<<"Case "<<i<<":"<<"\n";
        while(q--)
        {
            cin>>u>>v;
            cout<<lca(u,v)<<"\n";
        }
    }
    return 0;
}
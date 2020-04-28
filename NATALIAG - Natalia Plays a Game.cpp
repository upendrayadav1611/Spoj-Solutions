#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double

#define mod 1000000007
#define EULER 2.7182818284
#define INF 1000000000

#define pb push_back
#define ins insert
#define IT iterator
#define PQ priority_queue

#define fi first
#define se second
#define maxe max_element
#define mine min_element
#define er erase
#define lb lower_bound
#define ub upper_bound

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>


#define mem(v,i) memset(v,i,sizeof(v)) // v is array. To set all elements to 0 or -1 only. mem(arr,0);


#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORl(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORN(i,n) for(int i=(0);i<(n);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)

ll max(ll a,ll b)
{
    if(a>b)return a;return b;
}
ll min(ll a,ll b)
{
    if(a<b)return a;return b;
}

ll mypow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//..............................!!!!!!Get ready to fight!!!!!!............................
char ch[102][102];
int vis[102][102];
int dis[102][102];
int w,h;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool isvalid(int x,int y)
{
    return x>=0&&x<h&&y>=0&&y<w;
    
}
void bfs(int x,int y)
{
    dis[x][y]=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty())
    {
        pi p=q.front();
        q.pop();
        if(vis[p.fi][p.se]==1)
        continue;
        vis[p.fi][p.se]=1;
        for(int i=0;i<4;i++)
        {
            int u=p.fi+dx[i];
            int v=p.se+dy[i];
            if(isvalid(u,v)&&vis[u][v]==0&&ch[u][v]!='*')
            {
                q.push({u,v});
                dis[u][v]=dis[p.fi][p.se]+1;
            }
        }
    }
}



int main()
{
    fast
    int i,j,x,y,t;
    cin>>t;
    while(t--)
    {
        cin>>h>>w;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                dis[i][j]=0;
                vis[i][j]=0;
            }
        }
        int u,v;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='$')
                {
                    x=i;y=j;
                }
                if(ch[i][j]=='#')
                {
                    u=i,v=j;
                }
                
            }
        }
        bfs(x,y);
        if(vis[u][v]==1)
        {
            cout<<dis[u][v]<<"\n";
        }
        else
        cout<<-1<<"\n";
       
       
        
        
        
    }
    return 0;
}
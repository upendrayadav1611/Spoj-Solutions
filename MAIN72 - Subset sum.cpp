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
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
//..............................!!!!!!Get ready to fight!!!!!!............................



int main()
{
    fast
    ll t,n,m,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=0;
        ll a[n];
        for(i=0;i<n;i++)
        {
             cin>>a[i];
             m=m+a[i];
        }
       
        bool dp[m+1]={0};
        dp[0]=1;
        for(i=0;i<n;i++)
        {
            ll cur_element=a[i];
            for(ll j=m;j>=cur_element;j--)
            {
                if(dp[j]==1||dp[j-cur_element]==0)
                continue;
                else
                dp[j]=1;
            }
        }
        ll ans=0;
        for(i=0;i<m+1;i++)
        {
            if(dp[i]==1)
            {
                ans=ans+i;
            }
        }
        cout<<ans<<"\n";
        
    }
    
    return 0;
}
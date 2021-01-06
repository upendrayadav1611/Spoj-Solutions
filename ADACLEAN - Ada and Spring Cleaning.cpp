#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double

ll mod =  1e9+9;
#define EULER 2.7182818284
#define INF 1000000000

#define pb push_back
#define ins insert
#define IT iterator
#define PQ priority_queue
#define    nl           "\n"
#define sp " "
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
#define all(v) v.begin(),v.end()
#define mpi map<int,int>
#define mpl map<ll,ll>
#define umpi unordered_map<int,int>
#define umpl unordered_map<ll,ll>
#define si set<int>
#define sl set<ll>
#define msi multi_set<int>
#define msl multi_set<ll>

#define mem(v,i) memset(v,i,sizeof(v)) // v is array. To set all elements to 0 or -1 only. mem(arr,0);


#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define reprab(i,a,b) for(int i=(a);i>=(b);i--)
#define repll(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)
#define tc int t;cin>>t;while(t--)
template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nExecuted in: " << fixed
         << time_taken << setprecision(9);
    cout << " sec";
#endif
}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

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
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll n)
{
    return mypow(n, mod - 2);
}

ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
//..............................!!!!!!Get ready to fight!!!!!!............................
ll dp1[1000005],inv1[1000005],inv2[1000005],dp2[1000005];
void init(string input_string)
{
	ll p1 = 31;
	ll p2=53;
	ll p_power1 = 1,p_power2=1;
	inv1[0] = 1;
	inv2[0]=1;
	dp1[0] = (input_string[0] - 'a' + 1);
	dp2[0] = (input_string[0] - 'a' + 1);
 
 
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
 
		p_power1 = (p_power1 * p1) % mod;
		inv1[i] = mypow(p_power1 , mod - 2);
 
		dp1[i] = (dp1[i-1] + (ch - 'a' + 1)*p_power1) % mod;
		
		p_power2 = (p_power2 * p2) % mod;
		inv2[i] = mypow(p_power2 , mod - 2);
 
		dp2[i] = (dp2[i-1] + (ch - 'a' + 1)*p_power2) % mod;
	}
}

ll substringHash1(int L , int R)
{
	ll result = dp1[R];
	
	if(L > 0) result = (result - dp1[L-1] + mod) % mod;
	
	
	result = (result * inv1[L]) % mod;
	
	return result;
}
ll substringHash2(int L , int R)
{
	ll result = dp2[R];
	
	if(L > 0) result = (result - dp2[L-1] + mod) % mod;
	
	
	result = (result * inv2[L]) % mod;
	
	return result;
}
int main()
{   
     auto start = chrono::high_resolution_clock::now();
    fast
    tc{
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        init(s);
        //k--;
        //rep(i,n)cout<<dp[i]<<sp;
        //cout<<nl;
        mpl mp;
        int cnt=0;
        rep(i,n){
            if((i+k-1)<n){
                ll val1 = substringHash1(i,i+k-1);
                ll val2 = substringHash2(i,i+k-1);
               // cout<<i<<sp<<i+k-1<<nl;
                //cout<<val<<nl;
                if(!mp[val1]||!mp[val2])
                cnt++;
                mp[val1]++;
                mp[val2]++;
            }
        }
        cout<<cnt<<nl;
    }
    auto end = chrono::high_resolution_clock::now();
    TIME(start, end);
    return 0;
}
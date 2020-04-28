#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll binpow(ll a, ll b, ll m) 
{
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
	ll t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<binpow(a,b,10)<<"\n";
	}
	return 0;
	
}
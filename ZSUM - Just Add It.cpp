#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 10000007
ll binexp(ll a,ll n)
{
	if(n==0)
	return 1;
	ll res=1;
	while(n>0)
	{
		if(n%2)
		{
			res=(res*a)%mod;
			n--;
		}
		else
		{
			a=(a*a)%mod;
			n=n/2;
		}
	}
	return res;
}
int main()
{
	ll n,k;
	while(1)
	{
		cin>>n>>k;
		if(n==0&&k==0)
		break;
		ll a,b,c,d;
		a=(2*binexp(n-1,k))%mod;
		b=(2*binexp(n-1,n-1))%mod;
		c=binexp(n,n);
		d=binexp(n,k);
		cout<<(a+b+c+d)%mod<<"\n";
		
	}
	return 0;
}
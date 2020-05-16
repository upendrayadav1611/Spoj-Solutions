#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
	ll t,a,b,c;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ll ans=a*a-2*b;
		printf("%lld\n",ans);
	}
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,i;
	while(n)
	{
		cin>>n;
		if(n==0)
		break;
		ll a[n],b[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
		cin>>b[i];
		sort(a,a+n);
		sort(b,b+n,greater<int>());
		ll ans=0;
		for(i=0;i<n;i++)
		{
			ans+=a[i]*b[i];
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}
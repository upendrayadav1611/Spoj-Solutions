// for explanation:- https://medium.com/@rushyab/aggressive-cows-spoj-75a155bfe749
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll a[100005];
ll c,n;
bool check(ll x)
{
	ll cnt=1,i;
	ll last_pos=a[0];
	for(i=1;i<n;i++)
	{
		if((a[i]-last_pos)>=x)
		{
		    cnt++;
		    last_pos=a[i];
		}
		if(cnt==c)
		return true;
	}
	return false;
}
int main()
{
	ll t,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		ll low=0,high=1000000000,pos=0;
		while(low<=high)
		{
			ll mid=(low+high)/2;
			if(check(mid))
			{
				pos=mid;
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		cout<<pos<<"\n";
	}
}
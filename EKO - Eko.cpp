#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[1000005];
ll n,m;
ll max(ll a,ll b)
{
    if(a>b)
    return a;
    return b;
}
bool check(ll x)
{
	ll sum=0,i;
	for(i=0;i<n;i++)
	{
		sum=sum+max(0,a[i]-x);
		if(sum>=m)
		return true;
	}
	return false;
}
int main()
{
	cin>>n>>m;
	ll i;
	for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	ll low=0,high=1000000000,height=0;
	while(low<=high)
	{
		ll mid=(low+high)/2;
		if(check(mid))
		{
			height=mid;
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<height<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100005];
bool binary_search(ll low,ll high, ll val)
{
	while(low<=high)
	{
		ll mid=low+(high-low)/2;
		if(a[mid]==val)
		return true;
		if(a[mid]<val)
		return binary_search(mid+1,high,val);
		else
		return binary_search(low,mid-1,val);
	}
	return false;
}
int main()
{
	ll n,i,k;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
	ll cnt=0;
	sort(a,a+n);
	for(i=0;i<n-1;i++)
	{
		if(binary_search(i+1,n-1,a[i]+k))
		cnt++;
	}
	printf("%lld",cnt);
}
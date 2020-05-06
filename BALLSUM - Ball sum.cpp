#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	ll t,n,k;
	while(1)
	{
		cin>>n>>k;
		if(n==-1&&k==-1)
		break;
		ll q=n*(n-1)/2;
		ll w=k;
		ll p;
		if(w%2==0)
		{	w=w/2-1;
			p=w*(w+1);
		}
		else
		{
			w=w/2;
			p=w*w;
		}
		ll r=gcd(p,q);
		p=p/r;
		q=q/r;
		if(n==0||k==0||p==0)
		cout<<"0\n";
		else if(p==q)
		cout<<"-1\n";
		else
		{
			cout<<p<<"/"<<q<<"\n";
		}
	}
}
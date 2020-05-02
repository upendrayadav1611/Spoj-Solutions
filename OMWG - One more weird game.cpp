#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t,n,m;
	cin>>t;
	while(t--)
	{	
		cin>>n>>m;
		ll p=n*(m-1);
		ll q=m*(n-1);
		cout<<p+q<<"\n";
	}
	return 0;
}
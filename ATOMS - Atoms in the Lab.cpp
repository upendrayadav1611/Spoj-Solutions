#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	long double t,n,m,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>m;
		long double p=0;
		while(n<m)
		{
			n=n*k;
			p++;
		}
		if(n>m&&p!=0)
		p--;
		cout<<p<<"\n";
	}
}
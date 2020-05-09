#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t,n,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Case "<<i<<": ";
		if(n%4==3||n%4==0)
		cout<<"0\n";
		else
		cout<<"1\n";
	}
	return 0;
}
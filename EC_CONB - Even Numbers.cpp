#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,i;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		cout<<a[i]<<"\n";
		else
		{
			int temp=0,k=a[i];
			while(k)
			{
				temp=temp<<1;
				temp=temp+(k&1);
				k=k>>1;
			}
			cout<<temp<<"\n";
		}
	}
}
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
		if(n==1||(n==1&&m==1))
		cout<<"R\n";
		else if(m==1)
		cout<<"D\n";
		else if(n%2==0&m%2==0)
		{
		    if(n<=m)
		    cout<<"L\n";
		    else
		    cout<<"U\n";
		}
		else if(n%2!=0&&m%2!=0)
		{
		    if(n<=m)
		    cout<<"R\n";
		    else
		    cout<<"D\n";
		}
		else if(n%2==0&&m%2!=0)
		{
			if(n<m)
			cout<<"L\n";
			else
			cout<<"D\n";
		}
		else if(n%2!=0&&m%2==0)\
		{
			if(n<m)
			cout<<"R\n";
			else
			cout<<"U\n";
		}
	}
	return 0;
}
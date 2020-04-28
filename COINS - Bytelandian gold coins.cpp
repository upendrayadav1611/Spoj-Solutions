#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<int,ll>m;
ll fun(ll  n)
{	
	if(m[n])
	return m[n];
	if((n/2+n/3+n/4)<=n)
	m[n]= n;
	else 
	m[n] = fun(n/2)+fun(n/3)+fun(n/4);
	return m[n];
}
int main()
{
	int n;
	while(cin>>n)
	{	
		cout<<fun(n)<<endl;
	}
	return 0;
}
//For explanation see: https://youtu.be/sRWdCJyJg4E

#include<bits/stdc++.h>
using namespace std;
int fun(int n)
{
	int res=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			res=res/i;
			res=res*(i-1);
			while(n%i==0)
			{
				n=n/i;
			}
		}
	}
	if(n>1)
	{
	    res=res/n;
	    res=res*(n-1);
	}
	return res;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<fun(n)<<"\n";
	}
}
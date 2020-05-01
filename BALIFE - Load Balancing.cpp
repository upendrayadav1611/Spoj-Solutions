#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	while(1)
	{
		cin>>n;
		if(n==-1)
		break;
		int a[n];
		int sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum=sum+a[i];
		}
		if(sum%n!=0)
		cout<<-1<<"\n";
		else
		{
			int k=sum/n;
			for(i=0;i<n;i++)
			{
				a[i]=a[i]-k;
			}
			for(i=1;i<n;i++)
			{
				a[i]=a[i]+a[i-1];
			}
			int mx=INT_MIN;
			for(i=0;i<n;i++)
			{
			    if(abs(a[i])>mx)
			    mx=abs(a[i]);
			}
			cout<<mx<<"\n";
		}
		
	}
}
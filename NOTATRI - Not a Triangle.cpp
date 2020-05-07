#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	while(1)
	{
		cin>>n;
		if(n==0)
		break;
		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int sum=a[i]+a[j];
				//cout<<*lower_bound(a.begin(),a.end(),sum)<<"\n";
				int l=upper_bound(a+j+1,a+n,sum)-a;
				if(a[l]==a[i]+a[j])
				l++;
				ans=ans+(n-l);
			}
		}
		cout<<ans<<"\n";
	}
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[4],b[4],i,mx,res[4];
	while(1)
	{
		for(i=0;i<4;i++)
		cin>>a[i];
		for(i=0;i<4;i++)
		cin>>b[i];
		if(a[i]==-1)
		break;
		mx=0;
		int k;
		for(i=0;i<4;i++)
		{   
		    if(a[i]%b[i]==0)
		    k=a[i]/b[i];
		    else 
		    k=(a[i]/b[i])+1;
			mx=max(mx,k);
		}
		for(i=0;i<4;i++)
		{
			res[i]=max(0,mx*b[i]-a[i]);
		}
		for(i=0;i<4;i++)
		cout<<res[i]<<" ";
		cout<<"\n";
	}
}
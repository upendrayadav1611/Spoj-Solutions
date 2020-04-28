#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,i,j;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		i=n-1;
		while(i>0&&a[i-1]>=a[i])
		{
			i--;
		}
		if(i==0)
		cout<<"-1"<<"\n";
		else
		{
			j=n-1;
			while(a[i-1]>=a[j])
			j--;
			int temp=a[i-1];
			a[i-1]=a[j];
			a[j]=temp;
			reverse(a+i,a+n);
			for(i=0;i<n;i++)
			cout<<a[i];
			cout<<"\n";
		}
		
	}
	return 0;
}
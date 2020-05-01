#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	while(1)
	{
		cin>>n;
		if(n==0)
		break;
		int a[n+1];
		for(i=1;i<=n;i++)
		cin>>a[i];
		stack<int>st;
		int k=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				k++;
			}
			else
			{
				while(!st.empty()&&st.top()==k)
				{
					k++;
					st.pop();
				}
				st.push(a[i]);
			}
		}
		while(!st.empty()&&st.top()==k)
		{
			k++;
			st.pop();
		}
		if(st.empty())
		cout<<"yes\n";
		else
		cout<<"no\n";
	}
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int t=1;
	while(s[0]!='-')
	{	
		int k=0,l=0;
		stack<int>st;
		st.push('N');
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='{')
			{
				st.push(s[i]);
			}
			else
			{
				if(st.top()=='N')
				{
					st.push('{');
					k++;
				}
				else
				{
					st.pop();
				}
			}
			
		}
		while(st.top()!='N')
		{
			l++;
			st.pop();
		}
		cout<<t<<". "<<k+l/2<<endl;
		t++;
		cin>>s;
	}
}
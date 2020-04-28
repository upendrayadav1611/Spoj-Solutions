#include <bits/stdc++.h>
using namespace std;
int mass(char c)
{
	if(c=='H')
	return 1;
	else if(c=='C')
	return 12;
	else if(c=='O')
	return 16;
	else return -1;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int ans=0;
	cin>>s;
	stack<int> st;
	st.push('N');
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='H'||s[i]=='O'||s[i]=='C')
		{
			st.push(mass(s[i]));
		}
		else if(s[i]=='(')
		{
			st.push(s[i]);
		}
		else if(s[i]==')')
		{	
			int res=0;
			while(st.top()!='N'&&st.top()!='(')
			{
				res=res+st.top();
				st.pop();
			}
			if(st.top()=='(')
			st.pop();
			st.push(res);
		}
		else
		{
			int res;
			int a=s[i]-'0';
			res=a*st.top();
			st.pop();
			st.push(res);
		}
	}
	while(st.top()!='N')
	{
		ans=ans+st.top();
		st.pop();
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int pref(char c)
{
	if(c=='^')
	return 3;
	else if(c=='/'||c=='*')
	return 2;
	else if (c=='+'||c=='-')
	return 1;
	else return -1;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string s,ns;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ns="";
		stack<int> st;
		st.push('N');
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>=97&&s[i]<=122)
			ns=ns+s[i];
			else if(s[i]=='(')
			st.push(s[i]);
			else if(s[i]==')')
			{
				while(st.top()!='N'&&st.top()!='(')
				{
					char c=st.top();
					ns=ns+c;
					st.pop();
				}
				if(st.top()=='(')
				st.pop();
			}
			else
			{
				while(st.top()!='N'&&pref(s[i])<=pref(st.top()))
				{
					char c=st.top();
					ns=ns+c;
					st.pop();
				}
				st.push(s[i]);
			}
			
		}
		while(st.top()!='N')
		{
			char c=st.top();
			ns=ns+c;
			st.pop();
		}
		cout<<ns<<endl;
	}
	return 0;
}
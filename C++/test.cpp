#include <bits/stdc++.h>
using namespace std;
char str[300];
int a[300];
int main()
{
	int t;
	cin>>t;
	cin.getline(str,300);
	while (t--)
	{
		cin.getline(str,300);
		int len=strlen(str);
		//pre
		int k=0;
		for (int i=0;i<len;i++)
			if (str[i]!=' ')
				str[k++]=str[i];
		stack<int> s;
		memset(a,0,sizeof(a));
		for (int i=0;i<k;i++)
		{
			if (str[i]=='(')
				s.push(i);
			if (str[i]==')')
			{
				int temp=s.top();
				s.pop();
				a[temp]=i;
			}
		}
		/*
		for (int i=0;i<num;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		*/
		for (int i=0;i<k;i++)
		{
			if (str[i]=='(') str[i]=' ',str[a[i]]=' ';
			if (str[i]=='-' && str[i+1]=='(') i++;
		}
		int k1=0;
		for (int i=0;i<k;i++)
		{
			if (str[i]!=' ')
				str[k1++]=str[i];
		}
		for (int i=0;i<k1;i++)
		{
			//cout<<str[i]<<" "<<str[i+1]<<" "<<str[i+2]<<" "<<str[i+3]<<endl;
			if (str[i]=='-' && str[i+1]=='(' && 'A'<=str[i+2] && str[i+2]<='Z' && str[i+3]==')')
				str[i+1]=str[i+3]=' ';
		}
		for (int i=0;i<k1;i++)
			if (str[i]!=' ')
				cout<<str[i];
		cout<<endl;
	}
	return 0;
}
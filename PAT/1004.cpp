#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char s1[65],s2[65],s3[65],s4[65];
char ans[10];
char day[8][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	while (cin>>s1>>s2>>s3>>s4)
	{
		int i=0;
		for (i=0;i<strlen(s1) && i<strlen(s2);i++)
		{
			if (s1[i]==s2[i] && 'A'<=s1[i] && s1[i]<='Z')
			{
				cout<<day[s1[i]-'A']<<" ";
				break;
			}
		}
		i++;
		for (;i<strlen(s1) && i<strlen(s2);i++)
		{
			if (s1[i]==s2[i])
			{
				if ('A'<=s1[i] && s1[i]<='Z')
				{
					cout<<s1[i]-'A'+10<<":";
					break;
				}
				if ('0'<=s1[i] && s1[i]<='9')
				{
					cout<<0<<s1[i]-'0'<<":";
					break;
				}
			}
		}
		for (int i=0;i<strlen(s3) && i<strlen(s4);i++)
		{
			if (s3[i]==s4[i] && ('a'<=s3[i] && s3[i]<='z'))
			{
				if (i<10) cout<<0;
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
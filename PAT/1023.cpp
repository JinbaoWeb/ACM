#include <iostream>
#include <string.h>
using namespace std;
bool a[30], A[30], num[20], b[10];
char str1[10050],str2[10050];
int main()
{
	memset(a,true,sizeof(a));
	memset(num,true,sizeof(num));
	memset(b,true,sizeof(b));
	cin>>str1>>str2;
	int len=strlen(str1);
	for (int i=0;i<len;i++)
	{
		if ('A'<=str1[i] && str1[i]<='Z') a[str1[i]-'A']=false;
		if ('0'<=str1[i] && str1[i]<='9') num[str1[i]-'0']=false;
		if (str1[i]=='_') b[0]=false;
		if (str1[i]==',') b[1]=false;
		if (str1[i]=='.') b[2]=false;
		if (str1[i]=='-') b[3]=false;
		if (str1[i]=='+') b[4]=false;
	}
	len=strlen(str2);
	for (int i=0;i<len;i++)
	{
		if ('a'<=str2[i] && str2[i]<='z')
		{
			if (a[str2[i]-'a']==true)
				cout<<str2[i];
		}
		if ('A'<=str2[i] && str2[i]<='Z')
		{
			if (a[str2[i]-'A']==true && b[4]==true)
				cout<<str2[i];
		}
		if ('0'<=str2[i] && str2[i]<='9')
		{
			if (num[str2[i]-'0']==true)
				cout<<str2[i];
		}
		if (str2[i]=='_')
		{
			if (b[0]==true)
				cout<<str2[i];
		}
		if (str2[i]==',')
		{
			if (b[1]==true)
				cout<<str2[i];
		}
		if (str2[i]=='.')
		{
			if (b[2]==true)
				cout<<str2[i];
		}
		if (str2[i]=='-')
		{
			if (b[3]==true)
				cout<<str2[i];
		}
	}
	cout<<endl;
	return 0;
}
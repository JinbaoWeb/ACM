#include <iostream>
#include <string.h>
using namespace std;
int a[100];
int b[100];
string str1,str2;
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>str1>>str2;
	for (int i=0;i<str1.size();i++)
	{
		if ('0'<=str1[i] && str1[i]<='9')
			a[str1[i]-'0']++;
		else if ('a'<=str1[i] && str1[i]<='z')
			a[str1[i]-'a'+10]++;
		else //if ('A'<=str1[i] && str1[i]<='Z')
			a[str1[i]-'A'+36]++;
	}
	for (int i=0;i<str2.size();i++)
	{
		if ('0'<=str2[i] && str2[i]<='9')
			b[str2[i]-'0']++;
		else if ('a'<=str2[i] && str2[i]<='z')
			b[str2[i]-'a'+10]++;
		else //if ('A'<=str2[i] && str2[i]<='Z')
			b[str2[i]-'A'+36]++;
	}
	int ans=0,flag=0,ans2=0;
	for(int i=0;i<100;i++)
	{
		if (a[i]>=b[i])
		{
			ans+=(a[i]-b[i]);
		}
		else
		{
			flag=1;
			ans2+=(b[i]-a[i]);
		}
	}
	if (flag==1)
		cout<<"No "<<ans2<<endl;
	else
		cout<<"Yes "<<ans<<endl;
	return 0;
}
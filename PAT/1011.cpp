#include <iostream>
#include <string.h>
using namespace std;
char s[2000];
int a[10];
int main()
{
	while (cin>>s)
	{
		int len=strlen(s);
		memset(a,0,sizeof(a));
		for (int i=0;i<len;i++)
			a[s[i]-'0']++;
		for (int i=0;i<10;i++)
		{
			if (a[i])
			{
				cout<<i<<":"<<a[i]<<endl;
			}
		}
	}
	return 0;
}
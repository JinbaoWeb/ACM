#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
void add(char *a)
{
	int i=104;
	while (i)
	{
		if (a[i]=='0')
		{
			a[i]='1';
			break;
		}	
		else
			a[i--]='0';
	}
}
int mod(char *a,int n)
{
	int m;
	m=0;
	for(int i=0;i<105;i++)
		m=((m*10)%n+(a[i]-'0')%n)%n;
	return m;
}
int main()
{
	ofstream cout("0.txt");
	char a[105];
	int n=1;
	while (n<120)
	{
		cout<<'"';
		memset(a,'0',sizeof(a));
		while (1)
		{
			add(a);
			if (mod(a,n)==0)
				break;
		}
		int index;
		for (int i=0;i<105;i++)
			if (a[i]!='0')
			{
				index=i;
				break;
			}
		while (index<105)
		{
			cout<<a[index++];
		}
		n++;
		cout<<'"'<<",";
	}
	return 0;
} 

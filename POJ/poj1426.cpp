#include <iostream>
#include <string.h>
using namespace std;
void add(int *a)
{
	int i=101;
	while (i--)
	{
		if (a[i]!=0)
			a[i]=0;
		else
		{
			a[i]=1;
			break;
		}
	}
}
int main()
{
	int num[101],n;
	while (cin>>n)
	{
		if (n==0)
			break;
		memset(num,0,sizeof(num));
		while (1)
		{
			add(num);
			int m=0;
			for (int i=0;i<101;i++)
				m=((m*10)%n+num[i]%n)%n;
			if (m==0)
				break;
		}
		int index=0;
		for (int i=0;i<101;i++)
			if (num[i]!=0)
			{
				index=i;
				break;
			}	
		for (int i=index;i<101;i++)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}

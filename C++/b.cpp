#include <iostream>
using namespace std;
#include <string.h>
#include <algorithm>
#define M 500000
struct people
{
	int num,flag;
}p[M];
int main()
{
	int n,s;
	while (cin>>n)
	{
		memset(p,0,sizeof(p));
		int j=0;
		cin>>p[j].num;
		p[j++].flag=1;
		for (int i=1;i<n;i++)
		{
			int flagflag=0;
			cin>>s;
			for (int k=0;k<j;k++)
				if (s==p[k].num)
				{
					p[k].flag++;
					flagflag=1;
					break;
				}
			if (flagflag==0)
			{
				p[j].num=s;
				p[j++].flag=1;
			}	
		}
		for (int i=0;i<n;i++)
			if (p[i].flag%2!=0)
			{
				cout<<p[i].num<<endl;
			}
	}
	return 0;
}

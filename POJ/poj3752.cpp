#include <iostream>
#include <string.h>
using namespace std;
#define M 1000
int main()
{
	char s[27];
	s[0]='A';
	for (int i=1;i<26;i++)
		s[i]=(char)(s[i-1]+1);
	char map[M][M];
	int m,n;
	while (cin>>m>>n)
	{
		memset(map,'0',sizeof(map));
		int num=0;
		int i=0,j=0;
		int flag=0;
		while (num<n*m)
		{
			int flag1=0,flag2=0,flag3=0,flag4=0;
			while (j<n-flag)
			{
				if (map[i][j]=='0')
				{
					map[i][j]=s[num%26];
					num++;
				}
				j++;
				flag1=1;
			}
			if (flag1==1)
				j--;
			while (i<m-flag)
			{
				if (map[i][j]=='0')
				{
					map[i][j]=s[num%26];
					num++;
				}
				i++;
				flag2=1;
			}
			if (flag2==1)
				i--;
			while (j>=flag)
			{
				if (map[i][j]=='0')
				{
					map[i][j]=s[num%26];
					num++;
				}
				j--;
				flag3=1;
			}
			if (flag3==1)
				j++;
			while (i>=flag)
			{
				if (map[i][j]=='0')
				{
					map[i][j]=s[num%26];
					num++;
				}
				i--;
				flag4=1;
			}
			if (flag4==1)
				i++;
			i++;
			j++;
			flag++;		
		}
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
				cout<<"   "<<map[i][j];
			cout<<endl;
		}	
	}
	return 0;
}

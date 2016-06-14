#include <iostream>
#include <string.h>
#include <iomanip>
#define INF 0xffffff
using namespace std;
int main()
{
	char str[73];
	int sum[26],n,max;
	memset(sum,0,sizeof(sum));
	for (int c=1;c<=4;c++)
	{
		cin.getline(str,73);
		n=strlen(str);
		for (int i=0;i<n;i++)
			if (str[i]<='Z'&&str[i]>='A')
				sum[str[i]-'A']++;
	}
	max=sum[0];
	for (int i=1;i<26;i++)
		if (max<sum[i])
			max=sum[i];
	for (int i=max;i>0;i--)
	{
		int flag=1;
		for (int j=0;j<26;j++)
		{
		
			if (sum[j]>=i)
			{
				cout<<setw(flag)<<"*";
				flag=2;
			}	
			else
				flag+=2;	
		}
		cout<<endl;
	} 
	for (int i=0;i<25;i++)
		cout<<char('A'+i)<<" ";
	cout<<(char)'Z'<<endl;
	return 0;
}

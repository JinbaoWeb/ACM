#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char wall[14][26],space[26];
	int num[15];
	int n;
	while (cin>>n)
	{
		cin.getline(space,26);
		memset(num,0,sizeof(num));
		if (n==0)
			break;	
		for (int i=0;i<n;i++)
		{
			cin.getline(wall[i],26);
			int len=strlen(wall[i]);
			for (int j=0;j<len;j++)
				if (wall[i][j]=='X')
					num[i]++;
		}
		if (n==1)
		{
			cout<<0<<endl;
			continue;
		}
		int max=num[0];
		for (int i=1;i<n;i++)
			if (max<num[i])
				max=num[i];
		int count=0;
		for (int i=0;i<n;i++)
			count+=max-num[i];
		cout<<count<<endl;
	}
	return 0;
} 

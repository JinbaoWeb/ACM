#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,t;
	char people[1000][100],s[100];
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>people[i];
		cin>>t;
		for (int i=0;i<t;i++)
		{
			cin>>s;
			int count=0;
			for (int j=0;j<n;j++)
			{
				int len=strlen(people[j]);
				int len2=strlen(s);
				if (len2>len)
					continue;
				int flag=0;
				for (int k=0;k<len2;k++)
				{
					if (s[k]!=people[j][k])
					{
						flag=1;
						break;
					}
				}
				if (flag==0)
					count++;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}

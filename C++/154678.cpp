#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,m,n;
	char str[1001][1001],str2[1001][1001];
	cin>>t;
	while (cin>>m>>n)
	{
		int i,j,k,l;
		for (i=0;i<m;i++)
		{
			cin>>str[i];
		}	
		for (j=0;j<n;j++)
			cin>>str2[j];
		for (k=0;k<j;k++)
		{
			int count=0;
			int len=strlen(str2[k]);
			for (l=0;l<i;l++)
			{
				int flag=0;
				int len2=strlen(str[l]);
				if (len2<len)
					continue;
				
				for (int s=0;s<len;s++)
				{
					if (str[l][s]!=str2[k][s])
					{
						flag=1;
					}	
				}
				//cout<<flag<<endl;	
				if (flag==0)
					count++;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}

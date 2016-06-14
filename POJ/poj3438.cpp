#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	char str[1000][1005];
	int num[10];
	while (cin>>n)
	{
		
		for (int i=0;i<n;i++)
			cin>>str[i];
		for (int i=0;i<n;i++)
		{
			memset(num,0,sizeof(num));
			int len=strlen(str[i]);
			for (int j=0;j<len;j++)
			{
				num[str[i][j]-'0']+=1;
				if (str[i][j+1]!=str[i][j])
				{
					cout<<num[str[i][j]-'0']<<str[i][j];
					num[str[i][j]-'0']=0;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}

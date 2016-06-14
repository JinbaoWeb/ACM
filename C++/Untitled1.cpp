#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[100];
	while (cin>>str)
	{
		int len=strlen(str);
		for (int i=1;i<len;i++)
			if (len%i==0)
			{
				int ok=0;
				for (int j=i;j<len;j++)
					if (str[j]!=str[j%i])
					{
						ok=1;
						break;
					}
				if (ok==0)
				{
					cout<<i<<endl;
					break;
				}	
			}
	}
	return 0;
}

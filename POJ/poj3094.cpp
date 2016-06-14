#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[1000];
	while (cin.getline(str,1000))
	{
		if (strcmp(str,"#")==0)
			break;
		int n=strlen(str),sum=0;
		for (int i=0;i<n;i++)
		{
			if (str[i]==' ')
				continue;
			sum+=(str[i]-'A'+1)*(i+1);
		}
		cout<<sum<<endl;
	}
	return 0;
}

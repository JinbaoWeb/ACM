#include <iostream>
#include <string.h>
using namespace std;
int pow(int a)
{
	int b=1;
	for (int i=0;i<a;i++)
		b=b*9;
	return b;
}
int main()
{
	char str[20];
	int num[20];
	while (cin>>str)
	{
		if (strcmp(str,"0")==0)
			break;
		cout<<str<<": ";
		memset(num,0,sizeof(num));
		int len=strlen(str);
		for (int i=0;i<len;i++)
		{
			if (str[i]>'4')
				num[len-1-i]=str[i]-'1';
			else
				num[len-1-i]=str[i]-'0';
		}	
		for (int i=0;i<len;i++)
			num[i]*=pow(i);
		long long answer=0;
		for (int i=0;i<20;i++)
			answer+=num[i];
		cout<<answer<<endl;
	}
	return 0;
}

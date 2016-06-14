#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,a[]={9,7,3};
	char str[8];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>str;
		int len=strlen(str);
		int mul=0,index;
		for (int i=0;i<len;i++)
		{
			if (str[i]>='0'&&str[i]<='9')
				continue;
			else
				index=i; 
		}
		cout<<index<<endl;
		for (int i=0;i<=9;i++)
		{
			str[index]=i+'0';
			for (int j=0;j<len;j++)
				mul+=(str[j]-'0')*a[i%3];
			if (mul%10==0)
				break;	
		}
		cout<<"Scenario #"<<c<<":"<<endl;
		cout<<str<<endl;
		cout<<endl;
	}
	return 0;
}

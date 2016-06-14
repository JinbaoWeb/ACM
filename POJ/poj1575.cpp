#include <iostream>
#include <string.h>
using namespace std;
bool isvowel(char str)
{
	if (str=='a'||str=='e'||str=='i'||str=='o'||str=='u')
		return true;
	return false;
}
int main()
{
	char str[50];
	while (cin>>str)
	{
		int flag1=0,flag2=0,flag3=0;
		if (strcmp(str,"end")==0)
			break;
		int n=strlen(str);
		if (n<3)
		{
			for (int i=0;i<n;i++)
			{
				if (isvowel(str[i])==true)
					flag1=1;
				if (isvowel(str[i])==isvowel(str[i+1])&&(str[i]==str[i+1])&&(!(str[i]==str[i+1]&&(str[i]=='e'||str[i]=='o'))))
					flag3=1;
			}
		}
		else
		{
			for (int i=0;i<n-2;i++)
			{
				if (isvowel(str[i])==true)
					flag1=1;
				if (isvowel(str[i])==isvowel(str[i+1])&&isvowel(str[i+2])==isvowel(str[i+1]))
					flag2=1;
				if (isvowel(str[i])==isvowel(str[i+1])&&(str[i]==str[i+1])&&(!(str[i]==str[i+1]&&(str[i]=='e'||str[i]=='o'))))
					flag3=1;
			}
			for (int j=n-2;j<n-1;j++)
			{
				if (isvowel(str[j])==true)
					flag1=1;
				if (isvowel(str[j])==isvowel(str[j+1])&&(str[j]==str[j+1])&&(!(str[j]==str[j+1]&&(str[j]=='e'||str[j]=='o'))))
					flag3=1;
			}
			if (isvowel(str[n-1])==true)
					flag1=1;
			if (isvowel(str[n-1])==isvowel(str[n-2])&&isvowel(str[n-2])==isvowel(str[n-3]))
				flag2=1;
		}
		if (flag1==1&&flag2==0&&flag3==0)
			cout<<"<"<<str<<"> is acceptable."<<endl;
		else
			cout<<"<"<<str<<"> is not acceptable."<<endl;
		
	}
	return 0;
}

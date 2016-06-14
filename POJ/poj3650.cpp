#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[100],a[100];
	while (cin.getline(str,100))
	{
		if (strcmp(str,"#")==0)
			break;
		int len=strlen(str);
		int i,j=0;
		for (i=0;i<len;i++)
		{
			if (str[i]==' ')
			{
				a[j++]='%';
				a[j++]='2';
				a[j++]='0';
			}
			else
			{
				if (str[i]=='!')
				{
					a[j++]='%';
					a[j++]='2';
					a[j++]='1';
				}
				else
				{
					if (str[i]=='$')
					{
						a[j++]='%';
						a[j++]='2';
						a[j++]='4';
					}
					else
					{
						if (str[i]=='%')
						{
							a[j++]='%';
							a[j++]='2';
							a[j++]='5';
						}
						else
						{
							if (str[i]=='(')
							{
								a[j++]='%';
								a[j++]='2';
								a[j++]='8';
							}
							else
							{
								if (str[i]==')')
								{
									a[j++]='%';
									a[j++]='2';
									a[j++]='9';
								}
								else
								{
									if (str[i]=='*')
									{
										a[j++]='%';
										a[j++]='2';
										a[j++]='a';
									}
									else
										a[j++]=str[i];
								}
							}
						}
					}
				}
			}
		}
		a[j]=0;
		cout<<a<<endl;
	}
	return 0;
}

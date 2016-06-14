#include <iostream>
#include <string.h>
using namespace std;
#define size 100001
int main()
{
	char a[size],b[size];
	while (cin>>a>>b)
	{
		int len_a=strlen(a);
		int len_b=strlen(b);
		if (len_a>len_b)
		{
			cout<<"No"<<endl;
			continue;
		}
		int i,j=0;
		for (i=0;i<len_b;i++)
			if (a[j]==b[i])
				j++;
		if (j==len_a)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
} 

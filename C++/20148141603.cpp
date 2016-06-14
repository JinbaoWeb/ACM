#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	char a[5];
	cin>>n;
	for (int c=1;c<=n;c++)
	{
		cin>>a;
		int len=strlen(a);
		if (len==5)
			cout<<3<<endl;
		else
		{
			int count=0;
			char b[]={"one"};
			for (int i=0;i<len;i++)
				if (a[i]==b[i])
					count++;
			if (count==2)
				cout<<1<<endl;
			else
				cout<<2<<endl;
		}
	}
	return 0;
}

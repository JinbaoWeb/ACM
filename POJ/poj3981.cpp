#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[1100],b[1100];
	while (cin.getline(a,1100))
	{
		int n=strlen(a),j=0;
		for (int i=0;i<n;i++)
		{
			if (a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u')
			{
				b[j++]='w';
				b[j++]='e';
				i=i+2;
			}
			else
				b[j++]=a[i];
		}
		b[j]=0;
		cout<<b<<endl;
	}
	return 0;
}

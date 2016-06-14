#include <iostream>
#include <string.h> 
using namespace std;
int main()
{
	int t;
	char a[33];
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cin>>a;
		char b[33];
		int len=strlen(a);
		long long sum=0;
		for (int i=0;i<len;i++)
			sum=sum*2+a[i]-'0';
		long long s=sum;
		int k=0;
		while (s)
		{
			int ss=s%16;
			if (ss<=9&&ss>=0)
				b[k++]=char(ss+'0');
			else
				b[k++]=char(ss-10+'a');
			s=s/16;
		}
		while (k--)
			cout<<b[k];
		cout<<endl;
	}
	return 0;
}

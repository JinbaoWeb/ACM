#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,a,n,b,num[100];
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cin>>a>>n;
		for (int j=0;j<n;j++)
		{
			cin>>b;
			memset(num,0,sizeof(num));
			int k=0;
			while (b)
			{
				num[k++]=b%a;
				b/=a;
			}
			while (k--)
				cout<<num[k];
			cout<<endl;
		}
	}
	return 0;
}

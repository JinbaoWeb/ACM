#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a,number[10];
	while (cin>>a)
	{
		memset(number,0,sizeof(number));
		for (int j=1;j<=a;j++)
		{
			int i=j;
			while (i>0)
			{
				int s=i%10;
				number[s]++;
				i/=10;
			}
		}
		for (int i=0;i<10;i++)
			cout<<number[i]<<" ";
		cout<<endl;
	}
	return 0;
}

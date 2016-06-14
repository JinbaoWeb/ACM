#include <iostream>
#include <string.h>
using namespace std;
int number_a[10],number_b[10];
int main()
{
	int a,b;
	while (cin>>a>>b)
	{
		if (a==b&&b==0)
			break;
		if (a>b)
			swap(a,b);
		memset(number_a,0,sizeof(number_a));
		memset(number_b,0,sizeof(number_b));
		//int a=first(a,number_a);
		//int b=first(b,number_b);
		cout<<a<<endl;
		for (int i=0;i<10;i++)
			cout<<number_a[i]<<" ";
	}
	return 0;
}

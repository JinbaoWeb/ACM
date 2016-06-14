#include <iostream>
#include <string.h>
using namespace std;
int pow(int a)
{
	int s=1;
	for (int i=1;i<=a;i++)
		s*=2;
	return s;
}
int main()
{
	char a[33];
	while (cin>>a)
	{
		if (strcmp(a,"0")==0)
			break;
		int n=strlen(a);
		int sum=0;
		for (int i=0;i<n;i++)
			sum+=(a[i]-'0')*(pow(n-i)-1);
		cout<<sum<<endl;	
	}
	return 0;
} 

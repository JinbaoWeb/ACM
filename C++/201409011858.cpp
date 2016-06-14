#include <iostream>
#include <cmath>
using namespace std;
#define M 500000
int cmp(int a,int b,int c,int d)
{
	if (a<=b&&a<=c&&a<=d)
		return a;
	if (b<=a&&b<=c&&b<=d)
		return b;
	if (c<=a&&c<=b&&c<=d)
		return c;
	if (d<=a&&d<=b&&d<=c)
		return c;
}
int main()
{
	int t,n,a[M];
	int a1=0,a2=0,a3=0,a4=0;
	a[0]=1;
	int i=1;
	while (i<5845)
	{
		int s1=pow(2,a1+1)*pow(3,a2)*pow(5,a3)*pow(7,a4);
		int s2=pow(2,a1)*pow(3,a2+1)*pow(5,a3)*pow(7,a4);
		int s3=pow(2,a1)*pow(3,a2)*pow(5,a3+1)*pow(7,a4);
		int s4=pow(2,a1)*pow(3,a2)*pow(5,a3)*pow(7,a4+1);
	}
	cin>>t;
	while (cin>>n)
	{
		
	}
	return 0;
} 

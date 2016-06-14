#include <iostream>
using namespace std;
#define M 100005
int f(long long n,int d,int *a)
{
	int k=0;
	while (n)
	{
		a[k++]=n%d;
		n/=d;
	}
	return k;
}
int main()
{
	long long a,b,d;
	int num[M];
	while (cin>>a>>b>>d)
	{
		if (a==0&&b==0&&d==0)
			cout<<0<<endl;
		else
		{
			long long sum=a+b;
			int k=f(sum,d,num);
			for (int i=k-1;i>=0;i--)
				cout<<num[i];
			cout<<endl;
		}
		
	}
	return 0;
}

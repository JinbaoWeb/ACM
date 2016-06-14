#include <iostream>
using namespace std;
#define M 100000
#define N 58000
int main()
{
	long long i=0,aa[N];
	long long sum=0;
	for (i=1;i<M;i++)
	{
		sum+=i;
		aa[i]=sum;
	}
	long long n;
	while (cin>>n) 
	{
		if (n<0)
			n=-n;
		int i;
		for (i=1;i<M;i++)
			if (aa[i]<=n&&aa[i+1]>n)
				break;
		int a=n-aa[i],b=aa[i+1]-n;
		if (a>b)
		{
			i++;
			i+=b*2;
		}
		else
			i+=a*2;
		cout<<i<<endl;
	}
	return 0;
}

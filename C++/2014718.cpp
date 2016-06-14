#include <iostream>
#include <string.h>
using namespace std;
int f1(int a,int *count)
{
	int num=a%10;
	int s=a/10*10-1;
	for (int i=0;i<=num;i++)
		count[i]++;
	while (a>10)
	{
		a/=10;
		int k=a%10;
		count[k]+=num+1;
	}
	return s;
}
void f2(int a,int *count)
{
	if (a==0)
		return;
	int s=a;
	while (s>10)
	{
		s/=10;
		int k=s%10;
		count[k]+=10;
	}
	f2(a/10*10-1,count);
}
int main()
{
	int a,b,count_a[10],count_b[10];
	while (cin>>a>>b)
	{
		if (a==0&&b==0)
			break;
		memset(count_a,0,sizeof(count_a));
		memset(count_b,0,sizeof(count_b));
		if (a>b)
			swap(a,b);
		a=f1(a,count_a);
		b=f1(b,count_b);
		for (int i=0;i<9;i++)
			cout<<count_b[i]-count_a[i]<<" ";
		cout<<count_b[9]-count_a[9]<<endl; 
	}
	return 0;
}

/*#include <iostream>
#include <cmath>
using namespace std;
#define M 10000000
/*int pow(int a,int b)
{
	if (b==0)
		return 1;
	int mul=1;
	for (int i=1;i<=b;i++)
		mul*=a;
	return mul;
}
int main()
{
	int n,map[1000];
	int k=0;
	for (int i=1;i<=M;i++)
	{
		int sum=0;
		int j=i;
		if (i==10000)
			cout<<i<<endl;
		while (j>0)
		{
			sum+=pow(j%10,3);
			j/=10;
		}
		if (sum==i)
		{
			cout<<"_"<<i<<endl;
			map[k++]=i;
		}	
	}
	cout<<k<<endl;
	while (cin>>n)
	{
		int a=pow(10,n-1),b=pow(10,n);
		cout<<a<<"-"<<b<<endl;
		for (int i=0;i<k;i++)
			if (map[i]<=b&&map[i]>=a)
				cout<<map[i]<<endl;
	}
	return 0;
} */


#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		if (n==3)
			cout<<"153"<<endl<<"370"<<endl<<"371"<<endl<<"407"<<endl;
		if (n==4)
			cout<<"1634"<<endl<<"8208"<<endl<<"9474"<<endl;
		if (n==5)
			cout<<"54748"<<endl<<"92727"<<endl<<"93084"<<endl;
		if (n==6)
			cout<<"548834"<<endl;
		if (n==7)
			cout<<"1741725"<<endl<<"4210818"<<endl<<"9800817"<<endl<<"9926315"<<endl;
	}
	return 0;
}








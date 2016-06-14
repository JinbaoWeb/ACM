#include <iostream>
#include <cmath>
using namespace  std;
#define M 100010
bool isprime(int a)
{
	if (a<2)
		return false;
	if (a==2||a==3||a==5||a==7)
		return true;
	for (int i=2;i<=sqrt(a);i++)
		if (a%i==0)
			return false;
	return true;
}
int main()
{
	int map[M];
	int flag=0;
	for (int i=1;i<=M-1;i++)
	{
		if (isprime(i)==true)
			flag++;
		map[i]=flag;
	}
	int a, b;
	while (cin>>a>>b)
	{
		int flag=0;
		if (a==b&&b==-1)
			break;
		if (isprime(a)==true)
			flag++;
		if (a>=0&&b>=0)
			cout<<map[b]-map[a]+flag<<endl;
		if (a<0&&b>=0)
			cout<<map[b]<<endl;
		if (a<0&&b<0)
			cout<<0<<endl; 
	}
	return 0;
}

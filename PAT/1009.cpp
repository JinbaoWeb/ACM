#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[4];
int used[10000];
void f(int x)
{
	int cnt=0;
	while (x)
	{
		a[cnt++]=x%10;
		x/=10;
	}
}
int getMin()
{
	int ans=0;
	for (int i=0;i<4;i++)
	{
		ans=ans*10+a[i];
	}
	return ans;
}
int getMax()
{
	int ans=0;
	for (int i=3;i>=0;i--)
	{
		ans=ans*10+a[i];
	}
	return ans;
}
void f1(int x)
{
	if (x<10)
		cout<<"000"<<x;
	else if (10<=x  && x<100)
		cout<<"00"<<x;
	else if (100<=x && x<1000)
		cout<<"0"<<x;
	else
		cout<<x;
}
int main()
{
	int n;
	while (cin>>n)
	{
		memset(used,false,sizeof(used));
		while (true)
		{
			f(n);
			sort(a,a+4);
			int A=getMin();
			int B=getMax();
			n=B-A;
			if (used[n]==true)
				break;
			f1(B);
			cout<<" - ";
			f1(A);
			cout<<" = ";
			f1(n);
			cout<<endl;
			used[n]=true;
		}
	}	

}
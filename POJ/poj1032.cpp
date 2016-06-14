#include <iostream>
#include <string.h>
#include <algorithm> 
using namespace std;
int cmp(int a,int b)
{
	return a<b?1:0;
}
int main()
{
	int n,a[100];
	while (cin>>n)
	{
		for (int i=0;i<100;i++)
			a[i]=i+2;
		int j;
		for (j=0;j<100;j++)
		{
			if (n<a[j])
				break;
			n-=a[j];
		}
		if (n!=a[j-1])
		{
			for (int k=0;k<n;k++)
				a[j-1-k]++;
			sort(a,a+j-1,cmp);
			for (int s=0;s<j-1;s++)
				cout<<a[s]<<" ";
			cout<<a[j-1]<<endl;
		}
		else
		{
			for (int k=0;k<n-1;k++)
				a[j-1-k]++;
			a[j-1]++;
			sort(a,a+j-1,cmp);
			for (int s=0;s<j-1;s++)
				cout<<a[s]<<" ";
			cout<<a[j-1]<<endl;
		}
	} 
	return 0;
}

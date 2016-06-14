#include <iostream>
#include <string.h>
using namespace std;
void reverse(char *a,int *x)
{
	int len=strlen(a);
	for (int i=0;i<len;i++)
		x[i]=a[i]-'0';
}
void add(int *x,int *y,int *z)
{
	int flag=0;
	for (int i=0;i<99;i++)
	{
		z[i]=x[i]+y[i]+flag;
		flag=z[i]/10;
		z[i]%=10;
	}	
}
int main()
{
	int n,x[100],y[100],z[100];
	char a[100],b[100];
	cin>>n;
	for (int i=0;i<n;i++)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		cin>>a>>b;
		reverse(a,x);
		reverse(b,y);
		add(x,y,z);
		int k;
		for (k=98;k>=0;k--)
			if (z[k]!=0)
				break;
		int s;
		for (s=0;s<k;s++)
			if (z[s]!=0)
				break;
		for (int j=s;j<=k;j++)
			cout<<z[j];
		cout<<endl;
	}
	return 0;
}

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[100],b[100];
	int x[200],y[200],z[200];
	while (cin>>a>>b)
	{
		memset(z,0,sizeof(z));
		int len_a=strlen(a),len_b=strlen(b);
		for (int i=0;i<len_a;i++)
			x[i]=a[len_a-1-i]-'0';
		for (int i=0;i<len_b;i++)
			y[i]=b[len_b-1-i]-'0';
		for (int i=0;i<len_a;i++)
			for (int j=0;j<len_b;j++)
				z[i+j]+=x[i]*y[j];
		for (int i=0;i<len_a+len_b;i++)
			if (z[i]>=10)
			{
				z[i+1]+=z[i]/10;
				z[i]%=10;
			} 
		int index;
		for (int i=199;i>=0;i--)
			if (z[i]!=0)
			{
				index=i;
				break;
			}
		for (int i=index;i>=0;i--)
			cout<<z[i];
		cout<<endl;
	}
	return 0;
}

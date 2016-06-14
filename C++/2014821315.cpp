#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[33],b[33];
	int max[33],min[33],r[33];
	while (cin>>a>>b)
	{
		int len_a=strlen(a),len_b=strlen(b);
		memset(max,0,sizeof(max));
		memset(min,0,sizeof(min));
		memset(r,0,sizeof(r));
		if (len_a>len_b)
		{
			for (int k=len_b;k>=0;k--)
				b[k-len_b+len_a]=b[k];
			for (int s=0;s<len_a-len_b;s++)
				b[s]='0';
		}
		else
		{
			for (int k=len_a;k>=0;k--)
				a[k-len_a+len_b]=a[k];
			for (int s=0;s<len_b-len_a;s++)
				a[s]='0';
		}		
		len_a=strlen(a),len_b=strlen(b);
		if (strcmp(a,b)<0)
		{
			for (int i=0;i<len_a;i++)
				min[len_a-1-i]=a[i]-'0';
			for (int i=0;i<len_b;i++)
				max[len_b-1-i]=b[i]-'0';
		}
		else
		{
			for (int i=0;i<len_a;i++)
				max[len_a-1-i]=a[i]-'0';
			for (int i=0;i<len_b;i++)
				min[len_b-1-i]=b[i]-'0';
		}
		for (int i=0;i<20;i++)
		{
			if (max[i]<min[i])
			{
				max[i+1]--;
				max[i]+=10;
			}
			r[i]=max[i]-min[i];
		}
		int index;
		for (int k=32;k>=0;k--)
			if (r[k]!=0)
			{
				index=k;
				break;
			}
		for (int s=index;s>=0;s--)
			cout<<r[s];
		cout<<endl;
	}
	return 0;
}

#include <iostream>
#include <string.h>
using namespace std;
void add(int *x,int *y,int *z,int n)
{
	int flag=0;
	for (int i=0;i<=n;i++)
	{
		z[i]=x[i]+y[i]+flag;
		flag=z[i]/10;
		z[i]=z[i]%10;
	}
}
void sub(int *x,int *y,int *z,int n)
{
	for (int i=0;i<=n;i++)
	{
		if (x[i]<y[i])
		{
			x[i]+=10;
			x[i+1]--;
		}
		z[i]=x[i]-y[i];
	}
}
int main()
{
	int n,x[105],y[105],z[105],flag1=0,flag2=0,flag3=0;
	char a[105],b[105];
	while (cin>>n)
	{
		if (n==0)
			break;
		for (int i=0;i<n;i++)
		{
			memset(x,0,sizeof(x));
			memset(y,0,sizeof(y));
			memset(z,0,sizeof(z));
			flag1=0,flag2=0,flag3=0;
			cin>>a>>b;
			int len_a=strlen(a),len_b=strlen(b);	
			for (int i=0;i<len_a;i++)
				if (a[len_a-1-i]!='-')
					x[i]=a[len_a-1-i]-'0';	
			for (int i=0;i<len_b;i++)
				if (b[len_b-1-i]!='-')
					y[i]=b[len_b-1-i]-'0';
			if (a[0]=='-')
			{
				flag1=1;
				len_a--;
			}	
			if (b[0]=='-')
			{
				flag2=1;
				len_b--;
			}	
			int len=len_a>len_b?len_a:len_b;
			if (flag1==0&&flag2==0)
			{
				add(x,y,z,len);
				flag3=0;
			}	
			if (flag1==1&&flag2==1)
			{
				add(x,y,z,len);
				flag3=1;
			}
			if (flag1==0&&flag2==1&&((len_a>len_b)||(len_a==len_b&&a[0]>b[1])))
			{
				flag3=0;
				sub(x,y,z,len);
			}
			if (flag1==0&&flag2==1&&((len_a<len_b)||(len_a==len_b&&a[0]<=b[1])))
			{
				flag3=1;
				sub(y,x,z,len);
			}
			if (flag1==1&&flag2==0&&((len_a<len_b)||(len_a==len_b&&a[1]<b[0])))
			{
				flag3=0;
				sub(y,x,z,len);
			}	
			if (flag1==1&&flag2==0&&((len_a>len_b)||(len_a==len_b&&a[1]>=b[0])))
			{
				flag3=1;
				sub(x,y,z,len);
			}
			while (len)
				if (z[len--]!=0)
					break;
			for (int i=0;i<len;i++)
				cout<<z[len];
			cout<<endl;
		}
	}
	return 0;
} 

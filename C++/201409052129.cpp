#include <iostream>
#include <string.h>
using namespace std;
int cmp(char *a,char *b)	//比较a和b绝对值的大小，0表示相等，1表示a>b，-1表示a<b;
{
	int len_a=strlen(a),len_b=strlen(b),i=0,j=0;
	if (a[0]=='-')
	{
		len_a--;
		i++;
	}	
	if (b[0]=='-')
	{
		len_b--;
		j++;
	}	
	if (len_a>len_b)
		return 1;
	else
	{
		if (len_a<len_b)
			return -1;
		else
		{
			for (;i<len_a&&j<len_b;i++,j++)
			{
				if (a[i]>b[j])
					return 1;
				if (a[i]<b[j])
					return -1;
			}
			return 0;
		}
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
	char a[1005],b[1005];
	int t,x[1005],y[1005],z[1005];
	cin>>t;
	for (int c=0;c<t;c++)
	{
		cin>>a>>b;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		int len_a=strlen(a),len_b=strlen(b);
		for (int i=0;i<len_a;i++)
			if (a[i]!='-')
				x[len_a-i-1]=a[i]-'0';
		for (int j=0;j<len_b;j++)
			if (b[j]!='-')
				y[len_b-j-1]=b[j]-'0';
		int len=len_a>len_b?len_a:len_b;
		int k=cmp(a,b);
		if (k==1)
			sub(x,y,z,len);
		else
			sub(y,x,z,len);
		int index=0;
		for (int i=104;i>=0;i--)
		{
			if (z[i]!=0)
			{
				index=i;
				break;
			}
		}
		while (index)
			cout<<z[index--];
		cout<<z[index]<<endl;
	}
	return 0;
}

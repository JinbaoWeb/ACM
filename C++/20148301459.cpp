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
void add(int *x,int *y,int *z,int n)
{
	int flag=0;
	for (int i=0;i<=n;i++)
	{
		z[i]=x[i]+y[i]+flag;
		flag=z[i]/10;
		z[i]%=10;
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
	char a[105],b[105];
	int x[105],y[105],z[105];
	while (cin>>a>>b)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		int flag1=0,flag2=0,flag3=0;	//flag1表示a的正负，flag2表示b的正负，flag3表示a+b的正负；
		if (a[0]=='-')
			flag1=1;
		if (b[0]=='-')
			flag2=1;
		int len_a=strlen(a),len_b=strlen(b);
		for (int i=0;i<len_a;i++)
			if (a[i]!='-')
				x[len_a-i-1]=a[i]-'0';
		for (int j=0;j<len_b;j++)
			if (b[j]!='-')
				y[len_b-j-1]=b[j]-'0';
		int s=cmp(a,b);
		int len=len_a>len_b?len_a:len_b;
		if (flag1==0&&flag2==0)
		{
			flag3=0;
			add(x,y,z,len);
		}
		else
		{
			if (flag1==1&&flag2==1)
			{
				flag3=1;
				add(x,y,z,len);
			}
			else
			{
				if (s==1)
				{
					if (flag1==1&&flag2==0)
					{
						flag3=1;
						sub(x,y,z,len);
					}
					else
					{
						flag3=0;
						sub(x,y,z,len);
					}
				}
				else
				{
					if (s==0)
					{
						flag3=0;
						sub(x,y,z,len);
					}
					else
					{
						if (flag1==1&&flag2==0)
						{
							flag3=0;
							sub(y,x,z,len);
						}
						else
						{
							flag3=1;
							sub(y,x,z,len);
						}
					}
				}
			}
		}
		int index=0;
		for (int i=104;i>=0;i--)
		{
			if (z[i]!=0)
			{
				index=i;
				break;
			}
		}
		if (flag3==1)
			cout<<"-";
		while (index)
			cout<<z[index--];
		cout<<z[index]<<endl;
	}
	return 0;
} 

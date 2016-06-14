#include <iostream>
#include <string.h>
using namespace std;
bool istrue(char *a,int b)		//判断一个字符是否存在一个字符串里 
{
	int len=strlen(a);
	for (int i=0;i<len;i++)
		if (a[i]-'A'==b)
			return true;
	return false;
}
int main()
{
	int t;
	char left[3][20],right[3][20],result[3][20];
	bool coin[12];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		memset(coin,false,sizeof(coin));
		for (int i=0;i<3;i++)
		{
			cin>>left[i]>>right[i]>>result[i];
			if (strcmp(result[i],"even")==0)
			{
				int len=strlen(left[i]);
				for (int j=0;j<len;j++)
				{
					coin[left[i][j]-'A']=true;
					coin[right[i][j]-'A']=true;
				}
			}
		}
		int s,k,flag=0;
		for (s=0;s<12;s++)
		{
			if (coin[s]==true)
				continue;
			flag=0;
			for (k=0;k<2;k++)
			{
				flag=0;
				for (int i=0;i<3;i++)
				{
					if (strcmp(result[i],"even")==0)
					{
						if (istrue(left[i],s)==false&&istrue(right[i],s)==false)
							flag=0;
						else
							flag=1;
					}
					if (strcmp(result[i],"up")==0)
					{
						if (k==0)
						{
							if (istrue(right[i],s)==true)
								flag=0;
							else
								flag=1;
						}
						else
						{
							if (istrue(left[i],s)==true)
								flag=0;
							else
								flag=1;
						}
					}
					if (strcmp(result[i],"down")==0)
					{
						if (k==0)
						{
							if (istrue(left[i],s)==true)
								flag=0;
							else
								flag=1;
						}
						else
						{
							if (istrue(right[i],s)==true)
								flag=0;
							else
								flag=1;
						}
					}
					
					if (flag==1)
						break;
				}
				if (flag==0)
					break;
			}
			if (flag==0)
				break;
		}
		cout<<char(s+'A')<<" is the counterfeit coin and it is ";
		if (k==0)
			cout<<"light."<<endl;
		else
			cout<<"heavy."<<endl;
	}
	return 0;
} 

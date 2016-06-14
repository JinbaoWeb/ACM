#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	char str[55],s[55];
	cin>>n;
	cin.getline(str,55);
	for (int cases=1;cases<=n;cases++)
	{
		
		cin.getline(str,55);
		int len=strlen(str),k=0;
		for (int i=0;i<len;i++)
		{
			if (str[i]<='z'&&str[i]>='a')
				s[k++]=str[i];
		}
		s[k]=0;
		len=strlen(s);
		if (len<6)
		{
			cout<<"No"<<endl;
			continue;
		}
		int flag=0;
		for (int i=1;i*2<=len;i++)	//外 
		{
			flag=0;
			for (int k=0;k<i;k++)
			{
				if (s[k]!=s[len-i+k])
				{
					flag=1;
					break;
				}	
			}
			if (flag==1)
				continue;
			else
			{
				
				int flag=0;
				for (int j=1;j*2<=len-2*i-1;j++)	//内 
				{
					flag=0;
					for (int k=0;k<j;k++)
					{
						if (s[k+i]!=s[len-i+k-j])
						{
							flag=1;
							break;
						}	
					}
					if (flag==1)							//第二种 
					{
						int flag2=0;
						for (int jj=0;jj<i&&3*i<len;jj++)
						{
							if (s[jj]!=s[jj+i])
							{
								flag2=1;
								break;
							}
						}
						if (flag2==0)
						{
							if ((i==3&&s[i]!=s[i+2])||(i==2&&s[i]!=s[i+1]))
							{
								continue;
							}
							else
							{
								cout<<"Yes"<<endl;
								goto C;
							}
							
						}
					}	
					else									//第一种 
					{
						int ii=i+j,flag=0;
						for (int k=0;k<i;k++)
						{
							if (s[k]!=s[k+ii])
							{
								flag=1;
								break;
							}	
						}
						if (flag==0)
						{
							int flag3=0;
							if (i==j||len-3*(i+j)<=0)
							{
								for (int k=0;k<i;k++)
								{
									if (s[k]!=s[k+i])
									{
										flag3=1;
										break;
									}		
								}
								if (flag3==1)
								{
									cout<<"Yes"<<endl;
									goto C;
								}
							}
							else
							{
								cout<<"Yes"<<endl;
								goto C;
							}
							
						}
					}
				}	
			}
			
		}
		cout<<"No"<<endl;
		C:
			;
	}
	return 0;
}

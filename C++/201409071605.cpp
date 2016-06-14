#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	char str[1000],s[1000];
	cin>>n;
	cin.getline(str,1000);
	for (int cases=1;cases<=n;cases++)
	{
		cin.getline(str,1000);
		int len=strlen(str),k=0;
		for (int i=0;i<len;i++)
		{
			if ((str[i]<='z'&&str[i]>='a')||(str[i]<='Z'&&str[i]>='A'))
			{
				if (str[i]<='Z'&&str[i]>='A')
					str[i]=str[i]-'A'+'a';
				s[k++]=str[i];
			}	
		}
		s[k]=0;
		len=strlen(s);
		int i=1,j=1;
		for (i=1;i<len;i++)
		{
			for (j=1;j<len;j++)
			{
			//	cout<<i<<"   "<<j<<endl;
				int flag1=0,flag2=0,flag6=0;
				for (int k=0;k<i;k++)			//1-3
				{
					if (s[k]!=s[i+j+k])
					{
						flag1=1;
						break;
					}
				}
				if (flag1==1)
					continue;
			//	cout<<i<<"   -"<<j<<endl;
				for (int k=0;k<j;k++)	//2-4
				{
					if (s[i+k]!=s[i+j+i+k])
					{
						flag2=1;
						break;
					}
				}
				if (flag2==1)
					continue; 
				//cout<<i<<"   --"<<j<<endl; 
				if (i==j)				//1-2
				{
					for (int k=0;k<i;k++)
					{
						if (s[k]!=s[i+k])
						{
							flag6=1;
							break;
						}
					}
				}
				else
					flag6=1;
				if (flag6==0)
					continue;
				//cout<<i<<"---"<<j<<endl;
				if (len-2*(i+j)==i)			//first p
				{
					int flag3=0;
					for (int k=0;k<i;k++)
					{
						if (s[k]!=s[2*(i+j)+k])
						{
							flag3=1;
							break;
						}
					}
					if (flag3==0)
					{
						cout<<"Yes"<<endl;
						goto C;
					}
				}
				else		
				{
					if (len-3*(i+j)>0)			//second p
					{
						int ii=i+j;
						int flag5=0;
						for (int k=0;k<ii;k++)	//1+2 cmp 6+7
						{
							if (s[k]!=s[len-ii+k])
							{
								flag5=1;
								break;
							}
						}
						if (flag5==0)
						{
							int flag7=0;
							int len_c=len-3*(i+j);
							if (len_c==i)				//c cmp a
							{
								int flag8=0;
								for (int k=0;k<i;k++)
								{
									if (s[k]!=s[2*(i+j)+k])
									{
										flag8=1;
										break;
									}
								}
								if (flag8)
								{
									cout<<"Yes"<<endl;
									goto C;
								}
							}
							else
							{
								if (len_c==j)			//c cmp b
								{
									int flag9=0;
									for (int k=0;k<j;k++)
									{
										if (s[k]!=s[2*(i+j)+k])
										{
											flag9=1;
											break;
										}
									}
									if (flag9)
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
		}
		cout<<"No"<<endl;
		C:
			;
	}
	return 0;
}

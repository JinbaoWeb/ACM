#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	char left[3][20],right[3][20],result[3][8];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		for (int k=0;k<3;k++)
			cin>>left[k]>>right[k]>>result[k];	
		int i,j;
		for (i=0;i<12;i++)
		{
			int flag=0;
			for (j=0;j<2;j++)	//0指代轻，1指代重 
			{
				for (int k=0;k<3;k++)
				{
					int len=strlen(left[k]),count=0;
					if (strcmp(result[k],"even")==0)
						for (int s=0;s<len;s++)
						{
							if (left[k][s]-'A'==i||right[k][s]-'A'==i)
							{
								flag=1;
								break;
							}	
						}
					if (strcmp(result[k],"up")==0)
					{
						if (j==0)
						{
							count=0;
							for (int p=0;p<len;p++)
							{
								if (right[k][p]-'A'!=i)
									count++;
							}
							if (count==len)
								flag=1;
						}
						else
						{
							count=0;
							for (int p=0;p<len;p++)
							{
								if (left[k][p]-'A'!=i)
									count++;
							}
							if (count==len)
								flag=1;
						}
					}
					if (strcmp(result[k],"down")==0)
					{
						if (j==0)
						{
							count=0;
							for (int p=0;p<len;p++)
							{
								if (left[k][p]-'A'!=i)
									count++;
							}
							if (len==count)
								flag=1;
						}
						else
						{
							count=0;
							for (int p=0;p<len;p++)
							{
								if (right[k][p]-'A'!=i)
									count++;
							}
							if (count==len)
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
		cout<<char(i+'A')<<" is the counterfeit coin and it is ";
		if (j==0)
			cout<<"light";
		else
			cout<<"heavy";
		cout<<"."<<endl;
	}
	return 0;
}













/*#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char left[3][20],right[3][20],result[3][20];
	bool coin[13];
	int t;
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
				for (int k=0;k<len;k++)
				{
					coin[left[i][k]-'A']=true;
					coin[right[i][k]-'A']=true;
				}
			}
		}
		int flag2=0,i;
		for (i=0;i<12;i++)
		{
			if (coin[i]==true)
				break;
			int flag=0;
			for (int k=0;k<2;k++)
			{
				int count=0;
				for (int j=0;j<3;j++)
				{
					flag=0;
					if (strcmp(result[j],"even")==0)
					{
						flag=1;
						continue;
					}	
					if (strcmp(result[j],"up")==0)
					{
						if (k==0)
						{
							int len=strlen(right[j]);
							for (int s=0;s<len;s++)
							{
								if (right[j][s]-'A'==i)
								{
									flag=1;
									break;
								}
							}	
						}
						if (k==1)
						{
							int len=strlen(left[j]);
							for (int s=0;s<len;s++)
							{
								if (left[j][s]-'A'==i)
								{
									flag=1;
									break;
								}
							}
						}
					}
					if (strcmp(result[j],"down")==0)
					{
						if (k==0)
						{
							int len=strlen(left[j]);
							for (int s=0;s<len;s++)
							{
								if (left[j][s]-'A'==i)
								{
									flag=1;
									break;
								}
							}	
						}
						if (k==1)
						{
							int len=strlen(right[j]);
							for (int s=0;s<len;s++)
							{
								if (right[j][s]-'A'==i)
								{
									flag=1;
									break;
								}
							}
						}
					}
					if (flag==1)
						count++;
				}
				if (count==3)
				{
					flag2=1;
					break;
				}	
			}
			if (flag2==1)
				break;
		}
		cout<<char(i+'A')<<endl;
	}
	return 0;
}*/

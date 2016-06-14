#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	char left[3][20],right[3][20],result[3][8];
	bool used[26];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		memset(used,false,sizeof(used));
		for (int k=0;k<3;k++)
		{
			cin>>left[k]>>right[k]>>result[k];
			int len=strlen(left[k]);
			for (int i=0;i<len;i++)
			{
				used[left[k][i]-'A']=true;
				used[right[k][i]-'A']=true;
			}	
		}
		int i,j;
		for (i=0;i<26;i++)
		{
			if (used[i]==false)
				continue;
			int flag=0;
			for (j=0;j<2;j++)	//0指代轻，1指代重 
			{
				for (int k=0;k<3;k++)
				{
					int len=strlen(left[k]);
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
						int count;
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
						cout<<count<<"---------------------------"<<endl;
						cout<<"up        "<<char(i+'A')<<"-"<<flag<<"-"<<j<<endl;
					}
					if (strcmp(result[k],"down")==0)
					{
						if (j==0)
						{
							int count=0;
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
							int count=0;
							for (int p=0;p<len;p++)
							{
								if (right[k][p]-'A'!=i)
									count++;
							}
							if (count==len)
								flag=1;
						}
						cout<<"down        "<<char(i+'A')<<"-"<<flag<<"-"<<j<<endl;
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
		cout<<i<<endl;
		cout<<char(i+'A')<<" is the counterfeit coin and it is ";
		if (j==0)
			cout<<"light";
		else
			cout<<"heavy";
		cout<<"."<<endl;
	}
	return 0;
}

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char left[3][26],right[3][26],result[3][10];
	char s[3][10]={"even","up","down"};
	bool num[26];
	int t;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		memset(num,false,sizeof(num));
		int index;
		for (int i=0;i<3;i++)
		{
			cin>>left[i]>>right[i]>>result[i];
			if (strcmp(result[i],s[0])==0)
			{
				int lenleft=strlen(left[i]);
				for (int j=0;j<lenleft;j++)
					num[left[i][j]-'A']=true;
			}
			else
				index=i;
		}	
		int len=strlen(left[index]),k;
		for (k=0;k<len;k++)
		{
			if (num[left[index][k]-'A']==false)
			{
				cout<<left[index][k]<<" is the counterfeit coin and it is ";
				if (strcmp(result[index],s[1])==0)
					cout<<"heavy";
				else
					cout<<"light";
				cout<<"."<<endl;
				break;
			}
			if (num[right[index][k]-'A']==false)
			{
				cout<<right[index][k]<<" is the counterfeit coin and it is ";
				if (strcmp(result[index],s[2])==0)
					cout<<"heavy";
				else
					cout<<"light";
				cout<<"."<<endl;
				break;
			}
		}	
		
	}
	return 0;
}

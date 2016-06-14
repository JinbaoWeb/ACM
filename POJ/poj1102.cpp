#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int s;
	char str[20];
	while (cin>>s)
	{
		cin>>str; 
		if (s==0&&strcmp(str,"0")==0)
			break;
		int n=strlen(str);
		//////////////////////////////////1
		for (int i=0;i<n;i++)
		{
			cout<<" ";
			if (str[i]-'0'==1 || str[i]-'0'==4)
				for (int j=0;j<s;j++)
					cout<<" ";
			else
				for (int j=0;j<s;j++)
					cout<<"-";
			cout<<" ";
			cout<<" ";	
		}
		cout<<endl;
		//////////////////////////////////2			
		for (int k=0;k<s;k++)
		{
			for (int i=0;i<n;i++)
			{
				if (str[i]-'0'==1||str[i]-'0'==2||str[i]-'0'==3||str[i]-'0'==7)
				{
					for (int j=0;j<s+1;j++)
						cout<<" ";
					cout<<"|";
				}
				if (str[i]-'0'==4||str[i]-'0'==8||str[i]-'0'==9||str[i]-'0'==0)
				{
					cout<<"|";
					for (int j=0;j<s;j++)
						cout<<" ";
					cout<<"|";
				}
				if (str[i]-'0'==5||str[i]-'0'==6)
				{
					cout<<"|";
					for (int j=0;j<s+1;j++)
						cout<<" ";
				}
				cout<<" ";
			}
			cout<<endl;
		}
		//////////////////////////////////3
		for (int i=0;i<n;i++)
		{
			cout<<" ";
			if (str[i]-'0'==1||str[i]-'0'==7||str[i]-'0'==0)
				for (int j=0;j<s;j++)
					cout<<" ";
			else
				for (int j=0;j<s;j++)
					cout<<"-";
			cout<<" ";
			cout<<" ";
		}
		cout<<endl;
		//////////////////////////////////4
		for (int k=0;k<s;k++)
		{
			for (int i=0;i<n;i++)
			{
				if (str[i]-'0'==1||str[i]-'0'==3||str[i]-'0'==4||str[i]-'0'==5||str[i]-'0'==7||str[i]-'0'==9)
				{
					for (int j=0;j<s+1;j++)
						cout<<" ";
					cout<<"|";
				}	
				if (str[i]-'0'==6||str[i]-'0'==8||str[i]-'0'==0)
				{
					cout<<"|";
					for (int j=0;j<s;j++)
						cout<<" ";
					cout<<"|";
				}
				if (str[i]-'0'==2)
				{
					cout<<"|";
					for (int j=0;j<s+1;j++)
						cout<<" ";
				}
				cout<<" "; 
			}
			cout<<endl;
		}
		//////////////////////////////////5
		for (int i=0;i<n;i++)
		{
			cout<<" ";
			if (str[i]-'0'==1||str[i]-'0'==4||str[i]-'0'==7)
				for (int j=0;j<s;j++)
					cout<<" ";
			else
				for (int j=0;j<s;j++)
					cout<<"-";
			cout<<" ";
			cout<<" ";
		}
		cout<<endl;
		cout<<endl;
		//////////////////////////////////
	}
	return 0;
} 

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
	ifstream cin("2014.txt");
	char str[81];
	int len=0;
	while (cin>>str)
	{
		if (strcmp(str,"<br>")==0)
		{
			cout<<endl;
			len=0;
		}
		else
		{
			if (strcmp(str,"<hr>")==0)
			{
				cout<<endl;
				for (int i=0;i<80;i++)
					cout<<"-";
				//cout<<endl;
				len=0;
			}
			else
			{
				len+=strlen(str);
				if (len<=80)
					cout<<str<<" ";
				else
				{
					int k=strlen(str)-len+80;
					for (int i=0;i<k;i++)
						cout<<str[i];
					cout<<endl;
					for (int j=k;j<strlen(str);j++)
						cout<<str[j];
					cout<<" ";
				}
				len++;
			}
		} 
	}
	cout<<'\b'<<endl;
	return 0;
}

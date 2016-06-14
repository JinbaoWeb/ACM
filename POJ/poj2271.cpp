#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
	//ifstream cin("2014.txt");
	int count=0;	//一行内已经输出的字符个数 
	char word[81];	
	while (cin>>word)
	{
		if (strcmp(word,"<hr>")==0)
		{
			if (count!=0)
				cout<<endl;
			int i;
			for (i=0;i<80;i++)
				cout<<"-";
			cout<<endl;
			count=0;
		}
		else
		{
			if (strcmp(word,"<br>")==0)
			{
				cout<<endl;
				count=0;
			}
			else
			{
				if (count+strlen(word)+(count==0?0:1)>80)
				{
					cout<<endl;
					cout<<word;
					count=strlen(word);
				}
				else
				{
					if (count!=0)
						cout<<" ";
					cout<<word;
					count+=strlen(word)+1;
				}
			}
		}
	} 
	cout<<endl;
	return 0;
}

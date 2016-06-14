#include <iostream>
using namespace std;
int main()
{
	char map[105][105];
	int n;
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		int flag=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				int count=0;
				if (map[i+1][j]=='o'&&i+1<n)
					count++;
				if (map[i-1][j]=='o'&&i-1>=0)
					count++;
				if (map[i][j+1]=='o'&&j+1<n)
					count++;
				if (map[i][j-1]=='o'&&j-1>=0)
					count++;
				if (count%2==0)
					flag=0;
				else
				{
					flag=1;
					break;
				}	
			}
			if (flag==1)
				break;
		}
		if (flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
	return 0;
} 

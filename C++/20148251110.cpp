#include <iostream>
using namespace std;
int main()
{
	int num[10];
	while (cin>>num[0])
	{
		int flag=0;
		for (int i=1;i<10;i++)
		{
			cin>>num[i];
			if (flag==0&&num[i]!=0)
				flag=i;
		}	
		cout<<flag;
		num[flag]--;
		for (int i=0;i<10;i++)
			while (num[i])
			{
				cout<<i;
				num[i]--;
			}
		cout<<endl;
	}
	return 0;
}

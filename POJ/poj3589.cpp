#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	char a[6],b[6];
	while (cin>>a>>b)
	{
		int count_a=0,count_b=0;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				if (a[i]==b[j])
				{
					if (i==j)
						count_a++;
					else
						count_b++;
				}
		cout<<count_a<<"A"<<count_b<<"B"<<endl;
	}
	return 0;
}

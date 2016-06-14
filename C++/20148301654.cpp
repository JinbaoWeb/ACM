#include <iostream>
using namespace std;
int main()
{
	int n,s,x,y;
	while (cin>>n>>s)
	{
		int max=0,flag=0;
		for (int i=0;i<n;i++)
		{
			cin>>x>>y;
			if (max<100-y&&y)
				max=100-y;
			if (x*100+y<=s*100)
				flag=1;
		}
		if (flag==0)
			cout<<-1<<endl;
		else
			cout<<max<<endl;
	}
	return 0;
}

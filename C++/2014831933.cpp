#include <iostream>
#include <string.h>
using namespace std;
#define M 200000
int main()
{
	int m,n,t,q,c;
	cin>>c;
	bool used[M];
	while (cin>>n>>m)
	{
		memset(used,false,sizeof(used));
		for (int i=1;i<=n;i++)
		{
			cin>>t;
			used[t]=true;
		}
		int index=0;
		for (int j=1;j<=m;j++)
		{
			cin>>q;
			if (index>q)
			{
				cout<<index<<endl;
				continue;
			}
			for (int i=q;i<=M;i++)
			{
				if (used[i]==false)
				{
					cout<<i<<endl;
					index=i;
					break;
				}	
			}
		}
	}
	return 0;
}

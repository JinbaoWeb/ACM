#include <iostream>
#include <string.h>
using namespace std;
#define M 100005
void f(int *map,int *used,int i)
{
	int s=i;
	cout<<i;
	used[i]=1;
	while (map[map[i]]!=s)
	{
		used[map[i]]=1;
		i=map[i];
		cout<<" "<<i;
	}	
	used[map[i]]=1;
	if (map[i]!=i)
		cout<<" "<<map[i];
}
int main()
{
	int n,map[M],used[M];
	while (cin>>n)
	{
		
		for (int i=1;i<=n;i++)
			cin>>map[i];
		memset(used,0,sizeof(used));
		for (int i=1;i<=n;i++)
		{
			if (used[i]!=0)
				continue;
			cout<<"(";
			f(map,used,i);
			cout<<")";
		}
		cout<<endl;
	}
	
	return 0;
}

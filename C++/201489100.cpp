#include <iostream>
#include <algorithm>
using namespace std;
#define M 100005
struct laptop
{
	int a,b;
}l[M];
int cmp(laptop l1,laptop l2)
{
	if (l1.a<l2.a)
		return 1;
	else
	{
		if (l1.a==l2.a)
		{
			if (l1.b<l2.b)
				return 1;
			return 0;
		}
		return 0;
	}
}
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>l[i].a>>l[i].b;
	sort(l,l+n,cmp);
	for (int i=1;i<n;i++)
	{
		if (l[i].b<l[i-1].b)
		{
			cout<<"Happy Alex"<<endl;
			return 0;
		}
	}
	cout<<"Poor Alex"<<endl;
	return 0;
}

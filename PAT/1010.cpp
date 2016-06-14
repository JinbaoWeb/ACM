#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Node
{
	double a,b;
	double p;
}P[1005];
bool cmp(Node x,Node y)
{
	return x.p>=y.p;
}
int main()
{
	int n,m;
	cin>>n>>m;
		for (int i=0;i<n;i++)
			cin>>P[i].a;
		for (int j=0;j<n;j++)
		{
			cin>>P[j].b;
			P[j].p=P[j].b/P[j].a;
		}
		sort(P,P+n,cmp);
		double ans=0;
		for (int i=0;i<n;i++)
		{
			if (P[i].a<=m)
			{
				m-=P[i].a;
				ans+=P[i].b;
			}
			else
			{
				ans+=P[i].p*m;
				m=0;
				break;
			}
		}

		printf("%.2lf\n",ans);
	
	return 0;
}
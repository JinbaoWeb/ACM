#include <iostream>
#include <stdio.h>
using namespace std;
#define M 100005
#define INF 0xffffff
int main()
{
	int n,array[M],left[M],right[M],summax=-INF,c;
	scanf("%d",&c);
	//cin>>c;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
			scanf("%d",&array[i]);
		//	cin>>array[i];
		int suml=0,maxl=-INF;
		for (int k=0;k<n;k++)	//记录0-k之间的连续子区间和的最大值 
		{
			suml+=array[k];
			if (maxl<suml)
				maxl=suml;
			if (suml<0)
				suml=0;
			left[k]=maxl;
		}
		int sumr=0,maxr=-INF; 
		for (int k=n-1;k>=0;k--)	//记录k-n-1之间的连续子区间和的最大值 
		{
			sumr+=array[k];
			if (maxr<sumr)
				maxr=sumr;
			if (sumr<0)
				sumr=0;
			right[k]=maxr;
		}
		int summax=-INF;
		for (int i=0;i<n-1;i++)
		{
			if (summax<right[i+1]+left[i])
				summax=right[i+1]+left[i];
		}
		//cout<<summax<<endl;
		printf("%d\n",summax);
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct point{
	int t;
	double x,y;
}P[1005];
bool cmp(point a,point b){
	return a.t>b.t;
}
double D(point a,point b){
	return sqrt(((a.x-b.x)*1.0*(a.x-b.x)*1.0+((a.y-b.y)*1.0*(a.y-b.y)))*1.0);
}
int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%lf%lf",&P[i].t,&P[i].x,&P[i].y);
		sort(P,P+n,cmp);
		double ans=0;
		for (int i=1;i<n;i++){
			double d=D(P[i],P[i-1])/abs(P[i].t-P[i-1].t);
			//printf("%.10f\n",d);
			if (d-ans>=1e-9)
				ans=d;
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
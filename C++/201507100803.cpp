#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct NOde{
	int t,x;
}P[10000+5];
bool cmp(NOde a,NOde b){
	return a.t<b.t;
}
int main(){
	int t,n;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%d",&P[i].t,&P[i].x);
		sort(P,P+n,cmp);
		double max=0;
		for (int i=1;i<n;i++){
			double s=(abs(P[i].x-P[i-1].x)*1.0/(P[i].t-P[i-1].t));
			//cout<<s<<endl;
			if (s-max>0.00001)
				max=s;
		}
		printf("Case #%d: %.2f\n",cas,max);
	}
	return 0;
}
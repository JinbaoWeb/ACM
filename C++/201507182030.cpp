#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define pi 3.1415926
struct Node{
	int r;
	int a,b;
}P[10000+5];
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>P[i].r>>P[i].a>>P[i].b;
		}
		double ans=0;
		for (int i=-90;i<270;i++){
			int max=0;
			for (int j=0;j<n;j++){
				if (P[j].a<=i && i<P[j].b){
					if (max<P[j].r)
						max=P[j].r;
				}
			}
			ans+=0.5*max*max*1.0/360.0*M_PI;
		}
		printf("%.3f\n",ans*2);
	}
	return 0;
}
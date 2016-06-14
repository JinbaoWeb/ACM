#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
const int MAXN = 12;
const int MAXM = 60;
double a[MAXN][MAXM];
void init(){
	for (int i=0;i<12;i++){
		for (int j=0;j<60;j++){
			int t=i*60+j;
			double s=0.5*t;
			double f=6.0*t;
			while (s-360>eps){
				s-=360;
			}
			while (f-360>eps){
				f-=360;
			}
			double c=abs(s-f);
			if (c-180>eps){
				c=360-c;
			}
			a[i][j]=c;
		}
	}
}
int main(){
	init();
	int t;
	double k;
	cin>>t;
	while(t--){
		cin>>k;
		for (int i=0;i<12;i++){
			for (int j=0;j<60;j++){
				if (abs(a[i][j]-k)<=1.0/120){
					printf("%02d:%02d\n",i,j);
				}
			}
		}
	}

	return 0;
}
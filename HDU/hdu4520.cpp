#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
#define eps 1e-8
double a[MAXN];
int main(){
	int n;
	while (cin>>n){
		if (n==0)
			break;
		double Min=10.0,Max=-10.0;
		double sum=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (Min-a[i]>eps){
				Min=a[i];
			}
			if (a[i]-Max>eps){
				Max=a[i];
			}
			sum+=a[i];
		}
		sum=sum-Min-Max;
		double score=sum/(n-2);
		int ans=-1;
		double k=10.0;
		//cout<<score<<endl;
		for (int i=0;i<n;i++){
			//cout<<abs(a[i]-score)<<endl;
			if (k-abs(a[i]-score)>eps){
				k=abs(a[i]-score);
				ans=i+1;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
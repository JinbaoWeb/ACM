#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAXN = 5000000+10;
int p[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	for (int cas=1;cas<=T;cas++)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&p[i]);
		}
		sort(p,p+n);
		ll ans=0;
		ll tmp=1;
		int Maxabs=-1000005,Maxindex=-1,Minabs=1000005,Minindex=-1;
		for (int i=0;i<n;i++){
			if (Minabs>fabs(p[i])){
				Minabs=fabs(p[i]);
				Minindex=i;
			}
			if (Maxabs<fabs(p[i])){
				Maxabs=fabs(p[i]);
				Maxindex=i;
			}
		}
		//cout<<Maxabs<<" "<<Maxindex<<" "<<Minabs<<" "<<Minindex<<endl;
		if (a>=0 && b>=0){
			if (Maxindex!=n-1){
				ans=tmp*a*Maxabs*Maxabs+b*p[n-1];
			}
			else{
				ans=-1000005;
				for (int i=0;i<n-1;i++){
					ans=max(ans,max(tmp*a*p[i]*p[i]+b*p[n-1],tmp*a*p[n-1]*p[n-1]+b*p[i]));
				}
			}
		}
		if (a<0 && b>=0){
			if (Minindex!=n-1){
				ans=tmp*a*Minabs*Minabs+b*p[n-1];
			}
			else{
				ans=-1000005;
				for (int i=0;i<n-1;i++){
					ans=max(ans,max(tmp*a*p[i]*p[i]+b*p[n-1],tmp*a*p[n-1]*p[n-1]+b*p[i]));
				}
			}
		}
		if (a>=0 && b<0){
			if (Maxindex!=0){
				ans=tmp*a*Maxabs*Maxabs+b*p[0];
			}
			else{
				ans=-1000005;
				for (int i=1;i<n;i++){
					ans=max(ans,max(tmp*a*p[i]*p[i]+b*p[0],tmp*a*p[0]*p[0]+b*p[i]));
				}
			}
		}
		if (a<0 && b<0){
			if (Minindex!=0){
				ans=tmp*a*Minabs*Minabs+b*p[0];
			}
			else{
				ans=-1000005;
				for (int i=1;i<n;i++){
					ans=max(ans,max(tmp*a*p[i]*p[i]+b*p[0],tmp*a*p[0]*p[0]+b*p[i]));
				}
			}
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}

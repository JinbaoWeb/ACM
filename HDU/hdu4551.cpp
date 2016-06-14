#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int t,x,y,z;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>x>>y>>z;
		printf("Case #%d: ",cas);
		if (y%x!=0){
			printf("-1\n");
			continue;
		}
		int num=0,ii,jj;
		for (int i=1;i<=12;i++){
			for (int j=1;j<=31;j++){
				if (gcd(i,j)==x && i*j/x==y){
					num++;
					ii=i,jj=j;
				}
			}
		}
		if (num==0)
			printf("-1\n");
		else if (num==1)
			printf("%d/%02d/%02d\n",z,ii,jj);
		else
			printf("1\n");
	}
	return 0;
}
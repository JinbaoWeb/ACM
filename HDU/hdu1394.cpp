#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5000+10;
int a[4*MAXN];
int b[MAXN];
int lowbit(int x){
	return x&(-x);
}
void modify(int x,int add){
	while (x<=4*MAXN){
		a[x]=a[x]+add;
		x+=lowbit(x);
	}
}
int get_sum(int x){
	int ret=0;
	while (x!=0){
		ret+=a[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	int n;
	while (~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		int sum=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			sum+=(get_sum(n)-get_sum(b[i]));
			//cout<<get_sum(n)<<" "<<get_sum(b[i])<<endl;
			modify(b[i]+1,1);
		}
		int ans=sum;
		for (int i=1;i<=n;i++){
			sum=sum+(n-b[i]-1)-b[i];
			ans=min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
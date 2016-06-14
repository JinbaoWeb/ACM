#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000+100;
int c[MAXN];
int lowbit(int x){
	return x&(-x);
}
void modify(int x,int add){
	while (x<=MAXN){
		c[x]+=add;
		x+=lowbit(x);
	}
}
int get_sum(int x){
	int ans=0;
	while (x>0){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	int n,l,r;
	while (~scanf("%d",&n)){
		if (n==0)
			break;
		memset(c,0,sizeof(c));
		for (int i=0;i<n;i++){
			scanf("%d %d",&l,&r);
			modify(r+1,-1);
			modify(l,1);
		}
		for (int i=0;i<n-1;i++){
			printf("%d ",get_sum(i+1) );
		}
		printf("%d\n",get_sum(n) );
	}
	return 0;
}
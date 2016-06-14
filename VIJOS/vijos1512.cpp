#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000+10;
int c[MAXN][MAXN];
int lowbit(int x){
	return x&(-x);
}
int update(int x,int y,int k){
	for (;x<MAXN;x+=lowbit(x)){
		for (;y<MAXN;y+=lowbit(y)){
			c[x][y]+=k;
		}
	}
}
int getSum(int x,int y){
	int sum=0;
	for (;x>0;x-=lowbit(x)){
		for (;y>0;y-=lowbit(y)){
			sum+=c[x][y];
		}
	}
	return sum;
}
void init(){
	memset(c,0,sizeof(c));
}
int main(){
	int n,m,a,b,c,d;
	scanf("%d",&n);
	init();
	while (~scanf("%d",&m)){
		if (m==3) break;
		if (m==1){
			scanf("%d%d%d",&a,&b,&c);
			a++,b++;
			update(a,b,c);
		}
		if (m==2){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int ans=getSum(c+1,d+1)-getSum(c+1,b)-getSum(a,d+1)+getSum(a,b);
			printf("%d\n",ans);
		}
	}
	return 0;
}
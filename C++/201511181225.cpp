#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000+100;
int l[MAXN],r[MAXN];
int lowbit(int x){
	return x&(-x);
}
void updatel(int x,int add){
	while (x<MAXN){
		l[x]+=add;
		x+=lowbit(x);
	}
}
int get_suml(int x){
	int ans=0;
	while (x>0){
		ans+=l[x];
		x-=lowbit(x);
	}
	return ans;
}
void updater(int x,int add){
	while (x<MAXN){
		r[x]+=add;
		x+=lowbit(x);
	}
}
int get_sumr(int x){
	int ans=0;
	while (x>0){
		ans+=r[x];
		x-=lowbit(x);
	}
	return ans;
}
void init(){
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
}
struct OP{
	int a,b;
}O[MAXN];
int sor[MAXN*2];
int sor2[MAXN*2];
int L[MAXN*2];
int main(){
	int n,b2,b,cas=1;
	while (~scanf("%d",&n)){
		printf("Case #%d:\n",cas++);
		init();
		int k1=0,k2=0;
		int cnt=0;
		for (int i=1;i<=n;i++){
			scanf("%d%d",&O[i].a,&O[i].b);
			if (O[i].a==0){
				cnt++;
				sor[k1++]=O[i].b;
				sor2[k2++]=O[i].b+cnt;
				L[cnt]=O[i].b;
			}
		}
		sort(sor,sor+k1);
		sort(sor2,sor2+k2);
		int temp1=unique(sor,sor+k1)-sor;
		int temp2=unique(sor2,sor2+k2)-sor2;
		cnt=0;
		for (int i=1;i<=n;i++){
			//cout<<b<<"-----------\n";
			if (O[i].a==0){
				cnt++;
				b=lower_bound(sor,sor+temp1,O[i].b)-sor+1;
				b2=lower_bound(sor2,sor2+temp2,O[i].b+cnt)-sor2+1;
				int k1=get_suml(b-1);
				int k2=get_sumr(b2);
				cout<<k2-k1<<endl;
				updatel(b,1);
				updater(b2,1);
			}
			else{
				b=lower_bound(sor,sor+temp1,L[O[i].b])-sor+1;
				b2=lower_bound(sor2,sor2+temp2,L[O[i].b]+O[i].b)-sor2+1;
				updater(b2,-1);
				updatel(b,-1);
			}
		}
	}


	return 0;
}
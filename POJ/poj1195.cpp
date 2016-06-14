#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 1024+10;
typedef long long ll;
int c[MAXN][MAXN];
int lowbit(int x){
	return x&(-x);
}
void update(int x,int y,int add){
	for (int i=x;i<MAXN;i+=lowbit(i)){
		for (int j=y;j<MAXN;j+=lowbit(j)){
			c[i][j]+=add;
		}
	}
	/*
	while (x<MAXN){
		while (y<MAXN){
			c[x][y]+=add;
			//cout<<c[x][y]<<" "<<x<<" "<<y<<endl;
			y+=lowbit(y);
		}
		x+=lowbit(x);
	}
	*/
}
int get_sum(int x,int y){
	int ans=0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)){
			ans+=c[i][j];
			//cout<<c[x][y]<<" "<<x<<" "<<y<<endl;
		}
	}
	/*
	while (x>0){
		while (y>0){
			ans+=c[x][y];
			y-=lowbit(y);
		}
		x-=lowbit(x);
	}
	*/
	return ans;
}
int main(){
	int op,x1,y1,x2,y2,v;
	while (~scanf("%d",&op)){
		if (op==0){
			scanf("%d",&v);
			memset(c,0,sizeof(c));
		}
		if (op==1){
			scanf("%d%d%d",&x1,&y1,&v);
			//cout<<"-------\n"<<v<<endl;;
			update(x1+1,y1+1,v);
		}
		if (op==2){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1++,y1++,x2++,y2++;
			//cout<<get_sum(x2,y2)<<endl;
			int ans=get_sum(x2,y2)+get_sum(x1-1,y1-1)-get_sum(x1-1,y2)-get_sum(x2,y1-1);
			cout<<ans<<endl;
		}
		if (op==3)
			break;
	}
	return 0;
}
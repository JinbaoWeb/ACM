#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100000+10];
int b[100000+10];
int main(){
	int n,m,K,Q;
	int x,y;
	int x1,x2,x3,x4;
	while (~scanf("%d%d%d%d",&n,&m,&K,&Q)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=0;i<K;i++){
			scanf("%d%d",&x,&y);
			a[x]=1;
			b[y]=1;
		}
		for (int i=0;i<Q;i++){
			scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
			int flag=0;
			for (int ii=x1;ii<=x3;ii++){
				if (a[ii]==0){
					flag=1;
					break;
				}
			}
			for (int ii=x2;ii<=x4;ii++){
				if (b[ii]==0){
					flag=1;
					break;
				}
			}
			if (flag==1)
				cout<<"No\n";
			else
				cout<<"Yes"<<endl;
		}
	}
	return 0;
}
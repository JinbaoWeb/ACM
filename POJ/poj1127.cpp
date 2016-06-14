#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x1,x2,y1,y2;
}P[50];
int det(int x1,int y1,int x2,int y2){
	return x1*y2-x2*y1;
}
int main(){
	int n;
	while (~scanf("%d",&n)&&n){
		for (int i=1;i<=n;i++){
			scanf("%d%d%d%d",&P[i].x1,&P[i].y1,&P[i].x2,&P[i].y2);
		}
		int a,b;
		while (scanf("%d%d",&a,&b)){
			if (a==0&&b==0)
				break;
			int m1=P[a].x2-P[a].x1,n1=P[a].y2-P[a].y1;	//AB
			int m2=P[b].x1-P[a].x1,n2=P[b].y1-P[a].y1;	//AC
			int m3=P[b].x2-P[a].x1,n3=P[b].y2-P[a].y1;	//AD

			int m4=P[b].x2-P[b].x1,n4=P[b].y2-P[b].y1;	//CD
			int m5=P[a].x1-P[b].x1,n5=P[a].y1-P[b].y1;	//CA
			int m6=P[a].x2-P[b].x1,n6=P[a].y2-P[b].y1;	//CB

			if (det(m1,n1,m2,n2)*det(m1,n1,m3,n3)<0 && det(m4,n4,m5,n5)*det(m4,n4,m6,n6)<0){
				printf("CONNECTED\n");
			}
			else{
				printf("NOT CONNECTED\n");
			}

		}
	}
	return 0;
}
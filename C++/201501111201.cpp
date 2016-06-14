#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
using namespace std;
int a[100000+2];
int gcd(int x, int y){
	if (!x || !y) 
		return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
int main(){
	int n,t=1;
	while (~scanf("%d",&n)){
		
		int flag=0,index=-1,indexa=-1,indexb=-1;
		int ss=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if (i==0)
				ss=a[i];
			else{
				if (flag==0){
					index=-1;
					while (index++<i){
						if (gcd(a[i],a[index])==1){
							indexa=index;
							indexb=i;
							flag=1;
							break;
						}
					}
				}
					
			}
		}
		printf("Case %d: ",t++);
		if (flag==1){
			printf("%d\n",n-1);
			printf("%d %d\n",indexa+1,indexb+1);

			for (int i=0;i<n;i++){
				if (i==indexa||i==indexb)
					continue;
				printf("%d %d\n",indexa+1,i+1);
			}
/*
			printf("%d\n",n-1);

			printf("1 %d\n",index+1);
			for (int i=1;i<n;i++){
				if (i==index)
					continue;
				printf("1 %d\n",i+1);
			}
			*/
		}
		else{
			printf("-1\n");
		}
		printf("\n");
	}
	return 0;
}
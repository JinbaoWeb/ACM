#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	int t,n,m,p,q;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d%d",&n,&m,&p,&q);
		int Min=0xfffffff;
		for (int a=0;;a++){
			if (a>n)
				break;
			for (int b=0;;b++){
				if (a*m+b<n)
					continue;
				if (b>n)
					break;
				int temp=a*q+b*p;
				if (temp<Min)
					Min=temp;
			}
		}
		printf("%d\n",Min);
	}

	return 0;
}
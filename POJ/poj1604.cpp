#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 10000
int main(){
	int n,a[MAX+5];
	int mul=1;
	memset(a,0,sizeof(a));
	for (int i=1;i<MAX;i++){
		mul*=i;
		while (mul%10==0)
			mul/=10;
		mul%=100000;
		a[i]=mul%10;
	}
	while (cin>>n){
		printf("%5d -> %d\n",n,a[n]);
	}
	return 0;
}
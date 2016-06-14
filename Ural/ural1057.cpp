#include <iostream>
#include <stdio.h>
using namespace std;
int f[32][32];	//f[i][j]高度为i的二叉树含有1的个数为j的数量
void init(){
	f[0][0]=1;
	for (int i=1;i<=31;++i){
		f[i][0]=f[i-1][0];
		for (int j=1;j<=i;++j) 
			f[i][j]=f[i-1][j]+f[i-1][j-1];
	}
}
int main(){


	return 0;
}
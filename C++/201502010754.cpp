#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
using namespace std;
int fib[100],a[100],i,k;
bool work(int n,int step){	//递归搜索求解是否存在n是这些Fibonacci数组成的积
	if (n==1)
		return true;
	for (int j=step;j<k;j++){
		if (n%a[j]==0){
			if (work(n/a[j],j)==true)
				return true;
		}
	}
	return false;
}
int main(){
	int t,n;
	/*构造Fibonacci数组*/
	fib[0]=0;
	fib[1]=1;
	for (i=2;i<46;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	cin>>t;
	while (t--){
		cin>>n;
		if (n==0){
			cout<<"Yes"<<endl;
			continue;
		}
		k=0;
		for (int j=3;j<46;j++){	//用一个数组将Fibonacci数组中属于n的因子的数保存
			if (n%fib[j]==0)
				a[k++]=fib[j];
		}
		if (work(n,0)==true)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
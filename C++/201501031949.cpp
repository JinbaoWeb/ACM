#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int map[52][52];
bool used[52];
int n,m,a;
int f(int num){
	if (num==a)
		return 0;
	int count=0;
	for (int i=0;i<a;i++){
		if (used[i]==true)
			continue;
		count+=1+f(num+1);
	}
	return count;
}
int main(){
	
	while (cin>>n>>m){
		int a=a>b?a:b;
		memset(map,0,sizeof(map));
		memset(used,false,sizeof(used));
	}
	return 0;
}
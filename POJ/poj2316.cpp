#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("poj2316.txt");
	int a[12],len;
	char s[12];
	memset(a,0,sizeof(a));
	while (~scanf("%s",&s)){
		len=strlen(s);
		while (len--){
			a[len]+=s[len]-'0';
		}
	}
	for (int i=0;i<len;i++){
		printf("%d",a[i]%10);
	}
	printf("\n");
	return 0;
}
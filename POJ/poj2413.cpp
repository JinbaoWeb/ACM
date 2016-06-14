#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char fibs[10005][102];
void add(int n){
	int len_a=strlen(fibs[n-1]),len_b=strlen(fibs[n-2]);
	int p=len_a-1,q=len_b-1;
	int a[102],left=0;
	for (int i=0;i<102;i++){
		a[i]=left;
		if (p>=0)
			a[i]+=fibs[n-1][p--]-'0';
		if (q>=0)
			a[i]+=fibs[n-2][q--]-'0';
		left=a[i]/10;
		a[i]%=10;
	}
	int i;
	for (i=101;i>=0;i--){
		if (a[i]!=0)
			break;
	}
	int k=0;
	while (i>=0){
		fibs[n][k++]=a[i--]+'0';
	}
	fibs[n][k]=0;
}
bool cmp(char *a,char *b){
	int len_a=strlen(a),len_b=strlen(b);
	if (len_a>len_b)
		return true;
	if (len_a<len_b)
		return false;
	int n=0;
	while (n<len_a){
		if (a[n]-'0'>b[n]-'0')
			return true;
		if (a[n]-'0'<b[n]-'0')
			return false;
		n++;
	}
	return true;
}
int main(){
	strcpy(fibs[0],"1");
	strcpy(fibs[1],"2");
	int k=1;
	while (strlen(fibs[k++])<101){
		add(k);
	}
	char a[102],b[102];
	while(scanf("%s %s",a,b),strcmp(a,"0")!=0||strcmp(b,"0")!=0){
		int count=0;
		for (int i=0;i<=k;i++){
			if (cmp(fibs[i],a)==false)
				continue;
			if (cmp(fibs[i],a)==true && cmp(b,fibs[i])==true)
				count++;
			if (cmp(b,fibs[i])==false)
				break;
		}
		cout<<count<<endl;
	}
	return 0;
}
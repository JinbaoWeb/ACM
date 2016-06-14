#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define N 1010
char s[N];
int main(){
    int T,i,j;
    string a;
    scanf("%d",&T);
    while(T--){
    scanf("%s",s);
    a=s[0];
	char m='9';
	int j=0;
	for(i=0;s[i];i++){
		if(s[i]!='0'){//找到非0最小的数
			if(m>=s[i])m=s[j=i];
		}
	}
        for(i=1;s[i];i++){
			if(i==j)a=s[i]+a;
			else if(i>j){
				a+=s[i];
			}else if(i<j){
				if(s[i]>a[0])a+=s[i];
				else a=s[i]+a;
			}
        }
        cout<<a<<endl;
    }
return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	char x[102],y[102];
	int a[26],b[26];
	while (cin>>x>>y){
		int len_x=strlen(x),len_y=strlen(y),flag=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=0;i<len_x;i++)
			a[x[i]-'A']++;
		for (int i=0;i<len_y;i++)
			b[y[i]-'A']++;
		sort(a,a+26);
		sort(b,b+26);
		for (int i=0;i<26;i++){
			if (a[i]!=b[i]){
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<"YES"<<endl;
	}
	return 0;
}
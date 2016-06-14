#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char str[100000+5];
char s[100000+5];
char f[20000];
int main(){
	while (cin>>str){
		int len=strlen(str);
		for (int i=0;i<len;i++){
			f[str[i]]=str[(i+len-1)%len];
		}
		strcpy(s,str);
		sort(s,s+len);
		for (int i=0;i<len;i++){
			cout<<f[s[i]];
		}
		cout<<endl;
	}

	return 0;
}
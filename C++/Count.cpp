#include <iostream>
#include <string.h>
using namespace std;
int a[26];
int main(){
	char s[5000];
	while (cin.getline(s,5000)){
		memset(a,0,sizeof(a));
		int len=strlen(s);
		while (len--){
			if (s[len]<='Z'&&s[len]>='A')
				a[s[len]-'A']++;
			else if (s[len]<='z'&&s[len]>='a')
				a[s[len]-'a']++;
		}
		for (int i=0;i<26;i++){
			if (a[i])
				cout<<(char)(i+'A')<<": "<<a[i]<<endl;
		}
	}
	return 0;
}

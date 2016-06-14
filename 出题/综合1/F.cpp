#include <iostream>
#include <string.h>
using namespace std;
#define N 1000
int main(){
	int t;
	char str[N];
	cin>>t;
	while (t--){
		cin>>str;
		int len=strlen(str);
		for (int i=0;i<len;i++){
			if ('a'<=str[i] && str[i]<='z'){
				str[i]=str[i]-'a'+'A';
			}
		}
		cout<<str<<endl;
	}
	return 0;
}
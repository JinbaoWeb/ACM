#include <iostream>
using namespace std;
#define N 1000
int main(){
	int t;
	char s[N];
	cin>>t;
	while (t--){
		cin>>s;
		int len=strlen(s);
		for (int i=0;i<len;i++){
			cout<<s[i]<<endl;
		}
	}
	return 0;
}
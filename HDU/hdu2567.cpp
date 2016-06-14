#include <iostream>
using namespace std;
int main(){
	char s[100],str[100];
	int t;
	cin>>t;
	while (t--){
		cin>>s>>str;
		int len=strlen(s);
		for (int i=0;i<len;i++){
			if (i==len/2)
				cout<<str;
			cout<<s[i];
		}
		cout<<endl;
	}

	return 0;
}
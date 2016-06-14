#include <iostream>
using namespace std;
#define N 1000
int main(){
	int t;
	char s[N];
	cin>>t;
	cin.getline(s,N);
	while (t--){
		cin.getline(s,N);
		int len=strlen(s);
		for (int i=0;i<len;i++){
			if (s[i]==' ')
				s[i]='#';
		}
		cout<<s<<endl;
	}
	return 0;
}
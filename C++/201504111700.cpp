#include <iostream>
using namespace std;
int n;
char str[1000+2];
bool check(char s[]){
	for (int i=0;i<n;i++){
		if (s[i]!=s[n-1-i])
			return true;
	}
	return false;
}
int main(){
	while (cin>>n){
		cin>>str;
		cout<<check(str)<<endl;
		int k=-1;
		for (int i=0;i<n;i++){
			if (str[i]=='?'){
				k=i;
				str[i]='a';
			}
		}
		//cout<<k<<endl;
		if (k>=0){
			for (int i=0;i<26;i++){
				str[k]='a'+i;
				if (check(str)==true){
					break;
				}
			}
		}
		if (check(str)==true||n==1)
			cout<<str<<endl;
		else
			cout<<"QwQ"<<endl;
	}
	return 0;
}

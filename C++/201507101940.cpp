#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char s[10][10];
	int t;
	cin>>t;
	while (t--){
		for (int i=1;i<=6;i++)
			cin>>s[i];
		//cout<<s[1]<<" "<<s[3]<<" "<<s[6]<<endl;
		// 1
		if (strcmp(s[1],s[3])==0 && strcmp(s[1],s[5])==0 && strcmp(s[3],s[5])==0){
			cout<<"YES"<<endl;
			continue;
		}
		if (strcmp(s[1],s[3])==0 && strcmp(s[1],s[6])==0 && strcmp(s[3],s[6])==0){
			cout<<"YES"<<endl;
			continue;
		}
		if (strcmp(s[1],s[4])==0 && strcmp(s[1],s[5])==0 && strcmp(s[4],s[5])==0){
			cout<<"YES"<<endl;
			continue;
		}
		if (strcmp(s[1],s[4])==0 && strcmp(s[1],s[6])==0 && strcmp(s[4],s[6])==0){
			cout<<"YES"<<endl;
			continue;
		}
		//2
		if (strcmp(s[2],s[4])==0 && strcmp(s[2],s[6])==0 && strcmp(s[4],s[6])==0){
			cout<<"YES"<<endl;
			continue;
		}
		if (strcmp(s[2],s[4])==0 && strcmp(s[2],s[5])==0 && strcmp(s[4],s[5])==0){
			cout<<"YES"<<endl;
			continue;
		}
		if (strcmp(s[2],s[3])==0 && strcmp(s[2],s[6])==0 && strcmp(s[3],s[6])==0){
			cout<<"YES"<<endl;
			continue;
		}
		if (strcmp(s[2],s[3])==0 && strcmp(s[3],s[5])==0 && strcmp(s[2],s[5])==0){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}

}
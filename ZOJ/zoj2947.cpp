#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int t,n;
	char s[100];
	char s1[100],s2[100];
	cin>>t;
	while (t--){
		cin>>n;
		int k=0;
		while (n--){
			cin>>s;
			s1[k++]=s[0];
		}
		s1[k]=0;
		k=0;
		cin>>n;
		while (n--){
			cin>>s;
			s2[k++]=s[0];
		}
		s2[k++]=0;
		if (strcmp(s1,s2)==0)
			cout<<"SAME"<<endl;
		else
			cout<<"DIFFERENT"<<endl;
	}
	return 0;
}
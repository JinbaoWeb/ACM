#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
	int t,n;
	char s[102];
	cin>>t;
	while (t--){
		cin>>s>>n;
		int len = strlen(s);
		long long ans =0;
		for (int i=0;i<len;i++){
			ans = (ans*10+(s[i]-'0'))%n;
		}
		cout<<ans<<endl;
	}
	return 0;
}
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[26];
int main(){
	char s[15];
	while (cin>>s){
		int len=strlen(s);
		int n=len;
		memset(a,0,sizeof(a));
		for (int i=0;i<len;i++){
			a[s[i]-'a']++;
		}
		sort(a,a+26);
		
		if (n<3)
			cout<<"NO"<<endl;
		else{
			if (a[25]==a[24] && a[24]==a[23] && a[22]==0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}

	return 0;
}
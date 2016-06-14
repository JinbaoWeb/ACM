#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
char str[500];
char ans[500];
int main(){
	int t;
	cin>>t;
	cin.getline(str,500);
	while (t--){
		int k=0;
		cin.getline(str,500);
		int len=strlen(str);
		if ('a'<=str[0] && str[0]<='z')
			ans[k++]=str[0]-'a'+'A';
		else
			ans[k++]=str[0];
		for (int i=1;i<len;i++){
			if (str[i-1]==' ' && 'a'<=str[i] && str[i]<='z')
				ans[k++]=str[i]-'a'+'A';
			if (str[i-1]==' ' && 'A'<=str[i] && str[i]<='Z')
				ans[k++]=str[i];
		}
		ans[k++]=0;
		cout<<ans<<endl;
	}

	return 0;
}
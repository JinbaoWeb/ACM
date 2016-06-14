#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int cmp(char a,char b){
	int a1,b1;
	if ('A'<=a&&a<='Z')
		a1=a-'A';
	if ('A'<=b&&b<='Z')
		b1=b-'A';
	if ('a'<=a&&a<='z')
		a1=a-'a';
	if ('a'<=b&&b<='z')
		b1=b-'a';
	if (a1==b1)
		return a<b?1:0;
	return a1>b1?0:1;
}
int main(){
	int n;
	char s[13];
	cin>>n;
	while (n--){
		cin>>s;
		int len=strlen(s);
		sort(s,s+len,cmp);
		cout<<s<<endl;
		
		while (next_permutation(s, s + len))
			cout<<s<<endl;
	} 
	return 0;
} 

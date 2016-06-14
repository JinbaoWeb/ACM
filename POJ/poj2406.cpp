#include <iostream>
#include <string.h>
using namespace std;
char s[1000005];
int next[1000005]; 
int len;
void getnext(){	
	len=strlen(s);
	int i=0,j=-1;
	next[0]=-1;
	while (i<len){
		if (j==-1||s[i]==s[j])
			next[++i]=++j;
		else
			j=next[j];
	}
}
int main(){
	while (cin>>s){
		if (strcmp(s,".")==0)
			break;
		len=strlen(s);
		getnext();
		if (len%(len-next[len])==0)
			cout<<len/(len-next[len])<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[200100];
char father[300];
char son[300];
void init(){
	for (int i=0;i<28;i++){
		father[i+'a']='a'+i;
		son[i+'a']='a'+i;
	}
}
int main(){
	int n,m;
	char x,y;
	cin>>n>>m;
	cin>>s;
	init();
	for (int i=0;i<m;i++){
		cin>>x>>y;
		swap(father[x],father[y]);
	}
	for (int i=0;i<28;i++){
		son[father[i+'a']]=i+'a';
	}
	for (int i=0;i<n;i++)
		cout<<son[s[i]];
	cout<<endl;
	return 0;
}
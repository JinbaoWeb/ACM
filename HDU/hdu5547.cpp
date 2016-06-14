#include <bits/stdc++.h>
using namespace std;
char s[10][10];

int main(){
	int t;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		for (int i=0;i<4;i++)
			cin>>s[i];
		dfs(0,0);
	}

	return 0;
}
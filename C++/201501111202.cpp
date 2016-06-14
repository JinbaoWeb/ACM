#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
using namespace std;
char map[21][21];
char s[201][101];
char str[101];
int k,t,n,m;
int xa[]={-1,1,0, 0};
int ya[]={ 0,0,1,-1};

int main(){
	int x,y;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++){
				cin>>map[i][j];
				if (map[i][j]=='@'){
					x=i;
					y=j;
				}
			}
		cin>>k;
		for (int i=0;i<k;i++){
			cin>>s[i];
		}
		if (dfs(x,y,0)==true)
			cout<<
	}
	return 0;
}
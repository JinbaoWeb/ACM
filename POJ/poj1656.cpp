#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
int main(){
	int map[MAX][MAX];
	int t,x,y,l;
	char s[20];
	while (cin>>t){
		memset(map,0,sizeof(map));
		while (t--){
			cin>>s>>x>>y>>l;
			if (strcmp(s,"BLACK")==0){
				for (int i=x;i<x+l;i++){
					for (int j=y;j<y+l;j++){
						map[i][j]=1;
					}
				}
			}
			if (strcmp(s,"WHITE")==0){
				for (int i=x;i<x+l;i++){
					for (int j=y;j<y+l;j++){
						map[i][j]=2;
					}
				}
			}
			if (strcmp(s,"TEST")==0){
				int count=0;
				for (int i=x;i<x+l;i++){
					for (int j=y;j<y+l;j++){
						if (map[i][j]==1)
							count++;
					}
				}
				cout<<count<<endl;
			}
		}
	}
	return 0;
}
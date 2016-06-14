#include <iostream>
#include <string.h>
using namespace std;
char a[11][11];
int ans[11][11];
char str[20];
int main(){
	int r,c;
	while (cin>>str){
		if (strcmp(str,"ENDOFINPUT")==0)
			break;
		cin>>r>>c;
		for (int i=0;i<r;i++)
			cin>>a[i];
		for (int i=0;i<r-1;i++){
			for (int j=0;j<c-1;j++){
				ans[i][j]=(a[i][j]-'0'+a[i][j+1]-'0'+a[i+1][j]-'0'+a[i+1][j+1]-'0')/4;
				cout<<ans[i][j];
			}
			cout<<endl;
		}
		cin>>str;
	}
	return 0;
}
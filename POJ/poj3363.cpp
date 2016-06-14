#include <iostream>
#include <string.h>
using namespace std;
char map[105][105];
char ans[105][105];
int main(){
	int m,n,r,c;
	while (cin>>m>>n>>r>>c){
		if (m==0&&n==0&&r==0&&c==0)
			break;
		memset(ans,'0',sizeof(ans));
		for (int i=0;i<m;i++)
			cin>>map[i];
		int step=0;
		for (int i=0;i<=m-r;i++){
			for (int j=0;j<=n-c;j++){
				if (map[i][j]!=ans[i][j]){
					step++;
					for (int ii=0;ii<r;ii++){
						for (int jj=0;jj<c;jj++){
							if (ans[i+ii][j+jj]=='0')
								ans[i+ii][j+jj]='1';
							else
								ans[i+ii][j+jj]='0';						
						}
					}
				}
			}
		}
		int flag=0;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (map[i][j]!=ans[i][j]){
					flag=1;
					break;
				}
			}
		}
		if (flag==0)
			cout<<step<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
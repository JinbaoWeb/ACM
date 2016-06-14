#include <iostream>
using namespace std;
int map[101][501];
int main(){
	int m,n;
	while (cin>>m>>n){
		if (m==0&&n==0)	continue;
		int flag=0;
		for (int i=0;i<m;i++){
			int num=0;
			for (int j=0;j<n;j++){
				cin>>map[i][j];
				if (map[i][j]==1)
					num++;
			}
			if (num==n){
				flag=1;
			}
		}
		if (flag==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
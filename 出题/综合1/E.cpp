#include <iostream>
using namespace std;
#define N 100
int main(){
	int t,n,m;
	int a[N][N];
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int ans=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				for (int ii=0;ii<n;ii++){
					if (ii==i)
						continue;
					for (int jj=0;jj<m;jj++){
						if (jj==j)
							continue;
						if (a[i][j]+a[ii][jj]>ans)
							ans=a[i][j]+a[ii][jj];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
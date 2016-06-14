#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int a[805][805];
bool x[805],y[805];
int ans[805];
int main(){
	int n;
	while (cin>>n){
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		n*=2;
		for (int i=0;i<=n;i++){
			a[i][i]=0;
		}
		for (int i=1;i<n;i++){
			for (int j=0;j<i;j++){
				cin>>a[i][j];
				a[j][i]=a[i][j];
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"--------\n";
		int k=0;
		for (int i=0;i<n/2;i++){
			int Max=-1,ix=-1,iy=-1;
			for (int ii=0;ii<n;ii++){
				if (x[ii]==true || y[ii]==true)
					continue;
				for (int jj=0;jj<n;jj++){
					if (y[jj]==true || x[jj]==true)
						continue;
					if (Max<a[ii][jj]){
						Max=a[ii][jj];
						ix=ii,iy=jj;
					}
				}
			}
			x[ix]=true;
			y[iy]=true;
			cout<<ix+1<<" "<<iy+1<<endl;
			ans[k++]=iy+1;
			ans[k++]=ix+1;
		}
		for (int i=0;i<k;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
/*
2
999
999 2
1000 999 999
*/
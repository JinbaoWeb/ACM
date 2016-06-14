#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100
#define EPS 1e-6
/*		a:方程组对应的矩阵 
*		n：未知数个数 
*		l:自由元
*	  ans:存储解 
*/
int solve(double a[][MAXN],bool l[],double ans[],const int &n){
	int res=0,r=0;
	for (int i=0;i<n;i++)	
		l[i]=false;
	for (int i=0;i<n;i++){
		for (int j=r;j<n;j++)
			if (fabs(a[j][i])>EPS){
				for (int k=i;k<=n;++k)
					swap(a[j][k],a[r][k]);
				break;
			}
		if (fabs(a[r][i])<=EPS){
			res++;
			continue;			
		}
		for (int j=0;j<n;j++){
			if (j!=r && fabs(a[j][i])>EPS){
				double tmp=a[j][i]/a[r][i];
				for (int k=i;k<=n;k++){
					a[j][k]-=tmp*a[r][k];
				}
			}
		}
		for (int ii=0;ii<n;ii++){
			for (int jj=0;jj<n;jj++)
				cout<<a[ii][jj]<<"            ";
			cout<<endl;
		}
		l[i]=true;
		r++;
	} 
	for (int i=0;i<n;i++){
		if (l[i])
			for (int j=0;j<n;j++)
				if (fabs(a[j][r])>0)
					ans[i]=a[j][n]/a[j][i];
	}
	return n-res;
}
int main(){
	int n;
	bool l[MAXN];
	double a[MAXN][MAXN],ans[MAXN];
	while (cin>>n){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		cout<<solve(a,l,ans,n)<<endl;
	}
	return 0;
}

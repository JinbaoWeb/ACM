#include <iostream>
using namespace std;
int m=10000;
struct Matrix{
	long long mat[2][2];
};
Matrix add(Matrix a,Matrix b){
	Matrix ans;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			ans.mat[i][j]=a.mat[i][j]+b.mat[i][j];
			if (ans.mat[i][j]>=m){
				ans.mat[i][j]%=m;
			}
		}
	}
	return ans;
}
Matrix mul(Matrix a,Matrix b){
	Matrix ans;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			ans.mat[i][j]=0;
			for (int k=0;k<2;k++){
				ans.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
				if (ans.mat[i][j]>=m){
					ans.mat[i][j]%=m;
				}
			}
		}
	}
	return ans;
}
Matrix Init(){
	Matrix ans;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			if (i==j)
				ans.mat[i][j]=1;
			else
				ans.mat[i][j]=0;
		}
	}
	return ans;
}
Matrix exp(Matrix a,int k){
	Matrix ans=Init();
	while (k){
		if (k&1)
			ans=mul(ans,a);
		a=mul(a,a);
		k>>=1;
	}
	return ans;
}
int main(){
	Matrix a;
	a.mat[0][0]=a.mat[0][1]=a.mat[1][0]=1;
	a.mat[1][1]=0;
	int n;
	while (cin>>n&&n!=-1){
		Matrix ans=exp(a,n);
		cout<<ans.mat[0][1]%m<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
const int MAXN=1010;
const int MAXM=1010;
struct Matrix{
	int n,m;
	int a[MAXN][MAXM];
	void clear(){	//清空矩阵
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix operator +(const Matrix &b) const{	//矩阵加法
		Matrix tmp;
		tmp.n=n;
		tmp.m=m;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				tmp.a[i][j]=a[i][j]+b.a[i][j];
			}
		}
		return tmp;
	}
	Matrix operator -(const Matrix &b) const{	//矩阵减法
		Matrix tmp;
		tmp.n=n;
		tmp.m=m;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				tmp.a[i][j]=a[i][j]-b.a[i][j];
			}
		}
		return tmp;
	}
	Matrix operator *(const Matrix &b) const{	//矩阵乘法
		Matrix tmp;
		tmp.clear();
		tmp.n=n;
		tmp.m=b.m;
		for (int i=0;i<n;i++){
			for (int j=0;j<b.m;j++){
				for (int k=0;k<m;k++){
					tmp.a[i][j]+=a[i][k]*b.a[k][j];
				}
			}
		}
	}
};
int main(){

	return 0;
}
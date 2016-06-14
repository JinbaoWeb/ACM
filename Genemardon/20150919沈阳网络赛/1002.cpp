#include <iostream>  
#include <math.h>  
#include <stdio.h>  
using namespace std;  
typedef long long ll; 
#define ran 46500 
struct Matrix{  
    ll mat[2][2];  
};
ll bg[ran];
Matrix mul(Matrix a,Matrix b,ll mod){  
    Matrix ans;  
    for (int i=0;i<2;i++){  
        for (int j=0;j<2;j++){  
            ans.mat[i][j]=0;  
            for (int k=0;k<2;k++){  
                ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j]);  
                ans.mat[i][j]%=mod;  
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
Matrix exp(Matrix a,ll k,ll m){  
    Matrix ans=Init();  
    while (k){  
        if (k&1)  
            ans=mul(ans,a,m);  
        a=mul(a,a,m);  
        k>>=1;  
    }  
    return ans;  
}  
int mod_pow(int a,int b,int m){
    int res=1;
    while (b>0){
        if (b&1)    res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int main(){
	Matrix M;
	M.mat[0][0]=5;
	M.mat[0][1]=12;
	M.mat[1][0]=2;
	M.mat[1][1]=5;
	int t,x,o=0;
	ll p;
	cin>>t;
	while (t--){
		printf("Case #%d: ", ++o);
		cin>>x>>p;
		int s;
		Matrix ans=exp(M,i,p);
		for(int i = 0;i < ran;i++)
		{
			Matrix ans=exp(M,i,p);
			bg[i]=ans.mat[0][0];
			if(i && bg[i] == i)
			{
				s = i;
				break;
			}
		}
		ll n=mod_pow(2,x,s);
		n=(n+1)%s;
		cout<<2*bg[n]%p-1<<endl;
	}
	return 0;
}

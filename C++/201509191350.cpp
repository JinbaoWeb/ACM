#include <iostream>  
#include <math.h>  
#include <stdio.h> 
#include <fstream> 
using namespace std;  
typedef long long ll;  
struct Matrix{  
    ll mat[2][2];  
};  
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
ll temp[46337];
int main(){
	Matrix M;
	M.mat[0][0]=5;
	M.mat[0][1]=12;
	M.mat[1][0]=2;
	M.mat[1][1]=5;
	int t,x;
	ll p;
	cin>>t;
	while (t--){
		cin>>x>>p;
		ll n;
		temp[0]=1;
		for (n=1;n<=105;n++){
			Matrix ans=exp(M,n,p);
			ll tmp=ans.mat[0][0];
			cout<<tmp<<","<<endl;
			/*
			cout<<tmp<<endl;
			if (tmp==5){
				cout<<"1--------"<<endl;
				cout<<n<<endl;
			}
			if (tmp==49){
				cout<<"2--------"<<endl;
				cout<<n<<endl;
				//break;
			}
			if (tmp==485){
				cout<<"3--------"<<endl;
				cout<<n<<endl;
				break;
			}
			*/
		}
		for (int i=0;i<100;i++){
			if (temp[i]==1 && temp[i+1]==5 && temp[i+2]==49)
				cout<<i<<endl;
		}
		/*
		ll n=mod_pow(2,x,p-1);
		n=(n+1)%(p-1);
		Matrix ans=exp(M,n,p);
		ll tmp=ans.mat[0][0];
		cout<<2*tmp%p-1<<endl;
		*/
	}
	return 0;
}
#include <iostream>  
#include <math.h>  
#include <stdio.h>  
using namespace std;  
typedef long long ll;  
struct Matrix{  
    ll mat[2][2];  
};  
Matrix mul(Matrix a,Matrix b){  
    Matrix ans;  
    for (int i=0;i<2;i++){  
        for (int j=0;j<2;j++){  
            ans.mat[i][j]=0;  
            for (int k=0;k<2;k++){  
                ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j]); 
            }  
        }  
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
ll ans[46340];
void Init(){
    Matrix m;
    m.mat[0][0]=5;
    m.mat[0][1]=12;
    m.mat[1][0]=2;
    m.mat[1][1]=5;
    Matrix tmp;
    tmp.mat[0][0]=1;
    tmp.mat[0][1]=0;
    tmp.mat[1][0]=1;
    tmp.mat[1][1]=0;
    for (int i=1;i<46338;i++){
        tmp=mul(tmp,m);
        ans[i]=tmp.mat[0][0];
    }
}
int main(){
    int t,x,M;
    Init();
    cin>>t;
    for (int cas=1;cas<=t;cas++){
        cin>>x>>M;
        int k=mod_pow(2,x,M);
        int t1=ans[k+1]%M;
        cout<<2*t1-1<<endl;
    }

    return 0;
}
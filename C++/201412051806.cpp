#include <iostream>  
#include <cstring>  
#include <iomanip>  
#include <cmath>  
#include <string.h>
using namespace std;  
int m[9][9];  
int sum[9][9];  
int dp[15][9][9][9][9];  
int needsum(int x1,int y1,int x2,int y2)  
{return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];}  
int min(int a,int b)  
{ return a>b?b:a; }  
int fun(int k) 
{ 
    int t,a,b,c,e,d,MIN,i,j,m,n; 
    for(i=1;i<=8;i++) 
        for(j=1;j<=8;j++) 
            for(m=1;m<=8;m++) 
                for(n=1;n<=8;n++) 
                { 
                    t=needsum(i,j,m,n); 
                    dp[0][i][j][m][n]=t*t; 
                } 
    for(a=1;a<=k;a++) 
        for(i=1;i<=8;i++) 
            for(j=1;j<=8;j++) 
                for(m=1;m<=8;m++) 
                    for(n=1;n<=8;n++) 
                    { 
                        MIN=10000000; 
                        if((m-i+1)*(n-j+1)<a+1) {dp[a][i][j][m][n]=MIN;continue;} 
                        for(d=i;d<m;d++) 
                        { 
                            c=needsum(d+1,j,m,n); 
                            e=needsum(i,j,d,n); 
                            t=min(dp[a-1][i][j][d][n]+c*c,dp[a-1][d+1][j][m][n]+e*e); 
                            if(MIN>t) MIN=t; 
                        } 
                        for(b=j;b<n;b++) 
                        { 
                            c=needsum(i,b+1,m,n); 
                            e=needsum(i,j,m,b); 
                            t=min(dp[a-1][i][j][m][b]+c*c,dp[a-1][i][b+1][m][n]+e*e); 
                            if(MIN>t) MIN=t; 
                        } 
                        dp[a][i][j][m][n]=MIN; 
                    } 
    return dp[k][1][1][8][8]; 
}
int main()  
{  
    memset(sum ,0 ,sizeof(sum));  
    memset(dp ,-1 ,sizeof(dp));  
    int n;  
    cin>>n;  
    for (int i=1;i<9;i++)  
        for (int j=1,rowsum=0;j<9;j++)  
        {  
            cin>>m[i][j];  
            rowsum +=m[i][j];  
            sum[i][j] += sum[i-1][j] + rowsum;  
        }  
    cout<<fun(n-1)<<endl;
    cout<<sum[8][8]<<endl;
    double result = n*fun(n-1)-sum[8][8]*sum[8][8];  
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n))<<endl;     
    return 0;  
}  
/*int fun(int k) 
{ 
    int t,a,b,c,e,d,MIN,i,j,m,n; 
    for(i=1;i<=8;i++) 
        for(j=1;j<=8;j++) 
            for(m=1;m<=8;m++) 
                for(n=1;n<=8;n++) 
                { 
                    t=needsum(i,j,m,n); 
                    d[0][i][j][m][n]=t*t; 
                } 
                for(a=1;a<=k;a++) 
                    for(i=1;i<=8;i++) 
                        for(j=1;j<=8;j++) 
                            for(m=1;m<=8;m++) 
                                for(n=1;n<=8;n++) 
                                { 
                                    MIN=10000000; 
                                    if((m-i+1)*(n-j+1)<a+1) {d[a][i][j][m][n]=MIN;continue;} 
                                    for(d=i;d<m;d++) 
                                    { 
                                        c=needsum(d+1,j,m,n); 
                                        e=needsum(i,j,d,n); 
                                        t=min(d[a-1][i][j][d][n]+c*c,d[a-1][d+1][j][m][n]+e*e); 
                                        if(MIN>t) MIN=t; 
                                    } 
                                    for(b=j;b<n;b++) 
                                    { 
                                        c=needsum(i,b+1,m,n); 
                                        e=needsum(i,j,m,b); 
                                        t=min(d[a-1][i][j][m][b]+c*c,d[a-1][i][b+1][m][n]+e*e); 
                                        if(MIN>t) MIN=t; 
                                    } 
                                    d[a][i][j][m][n]=MIN; 
                                } 
                                return d[k][1][1][8][8]; 
}*/ 
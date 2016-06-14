#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
int main(){
	int n,t;
	char map[100][100];
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		int count=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++){
				if (i==n/2&&j==n/2)
					continue;
				if (i==j){
					char a[4];
					a[0]=map[i][n-1-j];
					a[1]=map[i][j];
					a[2]=map[n-1-i][j];
					a[3]=map[n-1-j][n-1-j];
					int max=0,num=0;
					char m;
					for (int ii=0;ii<4;ii++){
						num=0;
						for (int jj=0;jj<4;jj++){
							if (a[ii]==a[jj]){
								num++;
							}
						}
						if (max<num){
							max=num;
							m=a[ii];
						}
					}
					map[i][n-1-j]=m;
					map[i][j]=m;
					map[n-1-i][j]=m;
					map[n-1-i][n-1-i]=m;
					count+=4-max;
				}
				if (i==n/2||j==n/2){
					char a[4];
					a[0]=map[i][j];
					a[1]=map[n-1-i][j];
					a[2]=map[j][i];
					a[3]=map[j][n-i-1];
					int max=0,num=0;
					char m;
					for (int ii=0;ii<4;ii++){
						num=0;
						for (int jj=0;jj<4;jj++){
							if (a[ii]==a[jj]){
								num++;
							}
						}
						if (max<num){
							max=num;
							m=a[ii];
						}
					}
					map[i][j]=m;
					map[n-1-i][j]=m;
					map[j][i]=m;
					map[j][n-1-i]=m;
					count+=4-max;
				}
				char a[8];
				a[0]=map[i][j];
				a[1]=map[n-1-i][n-j-1];
				a[2]=map[n-1-j][n-1-i];
				a[3]=map[j][i];
				a[4]=map[i][n-1-j];
				a[5]=map[n-i-1][j];
				a[6]=map[n-1-j][i];
				a[7]=map[j][n-1-i];
				int max=0,num=0;
				char m;
				for (int ii=0;ii<8;ii++){
					num=0;
					for (int jj=0;jj<8;jj++){
						if (a[ii]==a[jj]){
							num++;
						}
					}
					if (max<num){
						max=num;
						m=a[ii];
					}
				}
				
				map[i][j]=m;
				map[n-1-i][n-j-1]=m;
				map[n-1-j][n-1-i]=m;
				map[j][i]=m;
				map[i][n-1-j]=m;
				map[n-i-1][j]=m;
				map[n-1-j][i]=m;
				map[j][n-1-i]=m;
				count+=8-max;
			}
		cout<<count<<endl;
	}
	return 0;
}
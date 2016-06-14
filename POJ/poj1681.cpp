#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
int map[300][300],ans[300],n;
bool l[300];	//是否为自由元
int Guass(){
	n=n*n;
	int res=0,r=0;
	for (int i=0;i<n;i++)
		l[i]=false;
	for (int i=0;i<n;i++){
		for (int j=r;j<n;j++){
			if (map[j][i]){
				for (int k=i;k<=n;k++){
					int temp=map[j][k];
					map[j][k]=map[r][k];
					map[r][k]=temp;
				}
				break;
			}
		}
		if (map[r][i]==0){
			res++;
			continue;
		}
		for (int j=0;j<n;j++){
			for (j!=i&&map[j][i]){
				for (int k=i;k<=n;k++)
					map[j][k]=map[j][i]^map[j][k];
			}
		}
		l[i]=true;
		r++;
	}
	for (int i=0;i<n;i++){
		if (l[i])
			for (int j=0;j<n;j++)
				if (map[j][i])
					ans[i]=map[i][n-1];
	}
}
int main(){
	int t;
	char s;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n*n;i++){
			map[i][n*n]=1;
			cin>>s;
			if (s=='y')
				map[i][n*n]=0;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				for (int k=0;k<n*n;k++)
					map[i*j-1][k]=0;
				if (i+1<=n)
					map[i*j-1][(i+1)*j-1]=1;
				if (i-1>0)
					map[i*j-1][(i-1)*j-1]=1;
				if (j+1<=n)
					map[i*j-1][i*(j+1)-1]=1;
				if (j-1>0)
					map[i*j-1][i*(j-1)-1]=1;
				map[i*j-1][i*j-1]=1;
			}
		}

	}
	retutn 0;
}
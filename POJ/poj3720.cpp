#include <iostream>
#include <string.h>
using namespace std;
int num[102][10];
int repeat[102];

int main(){
	int n,k;
	memset(num,0,sizeof(num));
	for (int i=2;i<101;i++){
		memset(repeat,-1,sizeof(repeat));
		int j=1;
		repeat[j]=0;
		int t=1;
		while (1){
			j*=10;
			num[i][j/i]++;
			j%=i;
			if (repeat[j]!=-1||j==0)
				break;
			repeat[j]=t++;
		}
	}
	while (cin>>n>>k){
		int ans = 0;
        for (int i = 2; i <= n; i++)
            ans += num[i][k];
        cout<<ans<<endl;
	}
	return 0;
}
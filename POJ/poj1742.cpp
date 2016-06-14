#include <iostream>
#include <string.h>
using namespace std;
#define N 100+5
#define MAX 100000+5
int main(){
	int n,m,a[N];
	bool used[MAX];
	while (cin>>n>>m){
		if (n==0&&m==0)
			break;
		memset(used,false,sizeof(used));
		for (int i=0;i<2*n;i++)
			cin>>a[i];
		
	}
	return 0;
}
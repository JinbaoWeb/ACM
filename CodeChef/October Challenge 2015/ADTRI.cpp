#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5*1000000+10;
bool arr[MAXN];
int gcd(int x, int y){
if (!x || !y) return x > y ? x : y;
for (int t; t = x % y; x = y, y = t);
return y;
}
void init(){
	memset(arr,false,sizeof(arr));
	for (int i=1;i<MAXN;i++){
		if (arr[i]==true)
			continue;
		for (int j=1;j*j<i;j+=2){
			int k=i-j*j;
			int tmp=sqrt(k*1.0);
			if (k==tmp*tmp){	// i=j*j+tmp*tmp
				if ((j+tmp)%2==1 && gcd(j,tmp)==1){
					arr[i]=arr[2*j*tmp]=true;
					int temp=sqrt(i*i-2*j*tmp);
					arr[temp]=true;
					break;
				}
			}
		}
	}
}
int main(){
	init();
	return 0;
}
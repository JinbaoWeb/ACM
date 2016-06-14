#include <iostream>
using namespace std;
int gcd(int x, int y){
	if (!x || !y) return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
int main(){
	int n,a[105];
	int num[10000];
	bool used[10000];
	while (cin>>n){
		for (int i=0;i<n;i++)
			cin>>a[i];
		int p=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				int k=gcd(a[i],a[j]);
				num[p++]=k;
			}
		}
		memset(used,false,sizeof(used));
		for (int i=0;i<p;i++){
			for (int j=i+1;j<p;j++){
				if (num[i]==num[j])
					used[j]=true;
			}
		}
		int count=0;
		for (int i=0;i<p;i++)
			if (used[i]==false)
				count++;
		cout<<count<<endl;
	}
	return 0;
}
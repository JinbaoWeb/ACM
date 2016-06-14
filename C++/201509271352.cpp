#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int a[N], f[N], d[N]; // d[i]用于记录a[0...i]的最大长度
int bsearch(const int *f, int size, const int &a) {
	int l=0, r=size-1;
	while( l <= r ){
		int mid = (l+r)/2;
		if( a > f[mid-1] && a <= f[mid] ) return mid;// >&&<= 换为: >= && <
		else if( a < f[mid] ) r = mid-1;
		else l = mid+1;
	}
}
int LIS(const int *a, const int &n){
	int i, j, size = 1;
	f[0] = a[0]; d[0] = 1;
	for( i=1; i < n; ++i ){
		if( a[i] <= f[0] ) j = 0; // <= 换为: <
		else if( a[i] > f[size-1] ) j = size++;// > 换为: >=
		else j = bsearch(f, size, a[i]);
		f[j] = a[i]; d[i] = j+1;
	}
	return size;
}
int main(void){
	int i, n;
	while( scanf("%d",&n) != EOF ){
		for( i=0; i < n; ++i ) scanf("%d", &a[i]);
		printf("%d\n", LIS(a, n));
		for (i=0;i<n;i++)
			cout<<f[i]<<" ";
		cout<<endl;
	}
}
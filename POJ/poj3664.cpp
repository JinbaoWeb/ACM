#include <iostream>
#include <algorithm>
using namespace std;
struct cow{
	int index,a,b;
}c[50005];
int cmp1(cow x,cow y){
	if (x.a>=y.a)
		return 1;
	return 0;
}
int cmp2(cow x,cow y){
	if (x.b>=y.b)
		return 1;
	return 0;
}
int main(){
	int n,k;
	while (cin>>n>>k){
		for (int i=0;i<n;i++){
			c[i].index=i;
			cin>>c[i].a>>c[i].b;
		}
		
		sort(c,c+n,cmp1);
		
		sort(c,c+k,cmp2);
		
		cout<<c[0].index+1<<endl;	
	}
	return 0;
} 

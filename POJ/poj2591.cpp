#include <iostream>
using namespace std;
#define M  10000001
int a[M];

int min(int a,int b){
	if (a>b)
		return b;
	return a;
}
int main(){
	a[1]=1;
	int x=1,y=1,k=2;
	for (int i=2;i<10000001;i++){
		a[i]=min(3*a[x]+1,2*a[y]+1);
		if (a[i]==3*a[x]+1)
			x++;
		if (a[i]==2*a[y]+1)
			y++;
	}
	int n;
	while (cin>>n)
		cout<<a[n]<<endl;
	return 0;
}

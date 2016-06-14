#include <iostream>
#include <string.h>
using namespace std;
int a[20];
bool used[20];
void work(){
	a[0]=1;
	int mul=1;
	for (int i=1;a[i-1]<1000000+1;i++){
		mul*=i;
		a[i]=mul;
	}
}
bool DFS(int x,int i){
	if (a[i]==x || x==0)
		return true;
	if (a[i]>x)
		return false;
	for (;i<10;i++){
		if (x-a[i]<0)
			continue;
		if (DFS(x-a[i],i+1))
			return true;
	}
	return false;
}
int main(){
	work();
	int n;
	while (cin>>n&&n>=0){
		if (n==0){
			cout<<"NO"<<endl;
			continue;
		}
		if (DFS(n,0)==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main(){
	int n,m,x,y;
	cin>>n>>m;
	int ans=0;
	int cnt=0,sum=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<2*m;j++){
			cin>>x;
			if (x==1)
				sum++;
			if (sum>=1 && j%2==0){
				cnt++;
				sum=0;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
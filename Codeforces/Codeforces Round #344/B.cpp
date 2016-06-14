#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int col,val;
}L[5005],R[5005];
int main(){
	int n,m,k,op,x,y;
	cin>>n>>m>>k;
	for (int i=0;i<5005;i++){
		L[i].col=0,L[i].val=0;
		R[i].col=0,R[i].val=0;
	}
	for (int i=1;i<=k;i++){
		cin>>op>>x>>y;
		if (op==1){
			L[x].col=y;
			L[x].val=i;
		}
		else{
			R[x].col=y;
			R[x].val=i;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<m;j++){
			//cout<<"------"<<L[i].val<<" "<<R[j].val;
			if (L[i].val>R[j].val)
				cout<<L[i].col<<" ";
			else
				cout<<R[j].col<<" ";
			//cout<<endl;
		}
		if (L[i].val>R[m].val)
			cout<<L[i].col<<endl;
		else
			cout<<R[m].col<<endl;
		
	}
	return 0;
}
#include <iostream>
using namespace std;
int main(){
	int n,m,k,x[1005];
	while (cin>>n>>m>>k){
		int answer=0;
		for (int i=1;i<=m+1;i++)
			cin>>x[i];
		for (int i=1;i<=m;i++){
			int s=x[i]^x[m+1];
			int count=0;
			while (s){
				if (s%2)
					count++;
				s/=2;
			}
			if (count<=k)
				answer++;
		}
		cout<<answer<<endl;
	}
	return 0;
} 

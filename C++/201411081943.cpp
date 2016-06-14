#include <iostream>
using namespace std;
struct person{
	long long clas,iq;
}p[1005];
int main(){
	int t,n,a;
	long long k;
	cin>>t;
	while (t--){
		cin>>n>>k;
		int flag=0;
		for (int i=0;i<n;i++){
			cin>>a;
			for (int j=0;j<a;j++){
				p[flag].clas=i;
				cin>>p[flag].iq;
				flag++;
			}
		}
		
		int count=0;
		for (int i=0;i<flag;i++){
			for (int j=i+1;j<flag;j++){
				if ((p[i].iq+p[j].iq>=k)&&(p[i].clas!=p[j].clas)){
					//cout<<p[i].iq<<" "<<p[i].clas<<" "<<p[j].iq<<" "<<p[j].clas<<endl;
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
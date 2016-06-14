#inlcude <iostream>
using namespace std;
#define N 10000
int main(){
	int t,n;
	int a[N];
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		int min=a[0];
		for (int i=1;i<n;i++){
			if (a[i]<min)
				min=a[i];
		}
		cout<<min<<endl;
	}
	return 0;
}
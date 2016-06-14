#include <iostream>
using namespace std;
int a[302];
char map[302][302];
int main(){
	int n;
	char x;
	while (cin>>n){
		for (int i=1;i<=n;i++)
			cin>>a[i];
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				cin>>map[i][j];
				if (map[i][j]=='1'){
					int m=i>j?i:j,n=i<j?i:j;
					if (a[n]>a[m]){
						//cout<<n<<" "<<m<<endl;
						swap(a[n],a[m]);
					}
					
					
				}
			}
		}
		
		for (int i=1;i<=n;i++){
			for (int j=i;j<a[i];j++){
				int k;
				for (k=j;k<=n;k++){
					if (a[k]==j)
						break;
				}
				if (map[i][k]=='1'){
					swap(a[i],a[k]);
					//cout<<i<<"       "<<k<<endl;
					break;
				}
			}
		}
		
		for (int i=1;i<n;i++)
			cout<<a[i]<<" ";
		cout<<a[n]<<endl;
	}
	return 0;
}
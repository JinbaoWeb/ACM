#include <iostream>
using namespace std;
int main(){
	int n;
	while (cin>>n&&n){
		if (n%6==2||n%6==3){
			if (n%2==0){
				int k=n/2;
				if (k%2==0){
					for (int i=k;i<=n;i+=2)	cout<<i<<" ";
					for (int i=2;i<=k-2;i+=2)	cout<<i<<" ";
					for (int i=k-3;i<=n-1;i+=2)	cout<<i<<" ";
					for (int i=1;i<=k+1;i+=2){
						if (i==k+1)
							cout<<i<<endl;
						else
							cout<<i<<" ";
					}
				}
				else{
					for (int i=k;i<=n-1;i+=2)	cout<<i<<" ";
					for (int i=1;i<=k-2;i+=2)	cout<<i<<" ";
					for (int i=k+3;i<=n;i+=2)	cout<<i<<" ";
					for (int i=2;i<=k+1;i+=2){
						if (i==k+1)
							cout<<i<<endl;
						else
							cout<<i<<" ";
					}
				}		
			}	
			else{
				int k=(n-1)/2;
				if (k%2==0){
					for (int i=k;i<=n;i+=2)	cout<<i<<" ";
					for (int i=2;i<=k-2;i+=2)	cout<<i<<" ";
					for (int i=k-3;i<=n-1;i+=2)	cout<<i<<" ";
					for (int i=1;i<=k+1;i+=2)	cout<<i<<" ";
					cout<<n<<endl;
				}
				else{
					for (int i=k;i<=n-2;i++)	cout<<i<<" ";
					for (int i=1;i<=k-2;i++)	cout<<i<<" ";
					for (int i=k+3;i<=n-1;i++)	cout<<i<<" ";
					for (int i=2;i<=k+1;i++)	cout<<i<<" ";
					cout<<n<<endl;
				}
			}
		}
		else{
			if (n%2==0){
				for (int i=2;i<=n;i+=2)	cout<<i<<" ";
				for (int i=1;i<=n-1;i+=2){
					if (i==n-1)
						cout<<i<<endl;
					else
						cout<<i<<" ";
				}
			}
			else{
				for (int i=2;i<=n-1;i+=2)	cout<<i<<" ";
				for (int i=1;i<=n;i+=2){
					if (i==n)
						cout<<i<<endl;
					else
						cout<<i<<" ";
				}
			}
		}
	}
	return 0;
}
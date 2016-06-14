#include <iostream>
using namespace std;
int main(){
	int n,t;
	cin>>t;
	while (cin>>n){
		int min=0xffffff;
		for (int x=1;x<=n;x++){
			if (n%x!=0)
				continue;
			for (int y=1;y<=n;y++){
				if (n%y!=0||n%(x*y)!=0)
					continue;
				int z=n/(x*y);
				int s=2*(x*y+x*z+y*z);
				if (min>s)
					min=s;
			}
		}
		cout<<min<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
int main(){
	int n,l,tree,t;
	char s[100],ss[100];
	while (cin>>n>>l){
		int max=0;
		for (int i=0;i<n;i++){
			cin>>tree;
			if (tree%l==0)
				continue;
			int k=l-tree%l;
			if (max<k)
				max=k;
		}
		cout<<max<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
#define MAX 1000
struct node{
	int value;
	node *left;
	node *right;
}array[MAX+5];
int main(){
	int n,r,root,child;
	while (cin>>n>>r){
		if (n==0&&r==0)
			break;
		for (int i=0;i<n;i++){
			cin>>array[i].value;
			array[i].left=NULL;
			array[i].right=NULL;
		}
		for (int i=0;i<n-1;i++){
			cin>>root>>child;
			if (array[root].left==NULL)
				array[root].left=array[child];
			else
				array[root].right=array[child];
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;
int n,m,type,x,l,r;
struct line{
	int left,right;
	ll sum;
}a[2*50000+2];
int array[50000+1];
int mod_pow(int a,int b,int m){
    int res=1;
    while (b>0){
        if (b&1)    res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
void build(int i,int j,int k){
	a[k].left=i;
	a[k].right=j;
	if (i==j)
		a[k].sum=array[i];
	else{
		int mid=(i+j)/2;
		build(i,mid,2*k);
		build(mid+1,j,2*k+1);
		a[k].sum=a[2*k].sum+a[2*k+1].sum;
	}
}
void update(int i,int j,int x){
	for (int m=1;m<2*n;m++){
		if (a[m].left==i && a[m].right==j){
			a[m].sum+=x*(j-i+1);
			if (i==j)
				return;
			int mid=(i+j)/2;
			update(i,mid,x);
			update(mid+1,j,x);
		}
	}
}
void modify(int x){
	int value=mod_pow(2,x,2333333);
	array[x]=value;
	build(0,n-1,1);
}
int query(int i,int j){
	for (int m=1;m<2*n;m++){
		if (a[m].left==i && a[m].right==j){
			return a[m].sum%2333333;
		}
	}
}
int main(){
	while (cin>>n>>m){
		for (int i=0;i<n;i++){
			cin>>array[i];
		}
		build(0,n-1,1);
		for (int i=0;i<m;i++){
			cin>>type;
			if (type==1){
				cin>>l>>r;
				cout<<query(l,r)<<endl;
			}
			if (type==2){
				cin>>x;
				modify(x);
				for (int m=1;m<2*n;m++){
					cout<<a[m].sum<<"----"<<endl;
				}
			}
			if (type==3){
				cin>>l>>r>>x;
				update(l-1,r-1,x);
			}
		}

	}
	return 0;
}
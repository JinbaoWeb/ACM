#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[502*502];
int b[502*502];
int ans[502];
map<int,int> mp;
bool f(int x){
	for (int i=1;;i++){
		if (i*i==x)
			return true;
		if (i*i>x)
			return false;
	}
}
int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 
int main(){
	int n;
	scanf("%d",&n);
	map<int, string>::iterator  it;
	for (int i=0;i<n*n;i++){
		scanf("%d",&a[i]);
		if (mp.find(a[i])==mp.end()){
			mp[a[i]]=1;
		}
		else{
			mp[a[i]]++;
		}
	}
	sort(a,a+n*n);
	int tmp=unique(a,a+n*n)-a;
	cout<<tmp<<endl;
	int k=0;
	for (int i=tmp-1;i>=0;i--){
		if (f(mp[a[i]])==true){
			for (int j=0;j<k;j++){
				int s=gcd(ans[j],a[i]);
				mp[s]--;
			}
			ans[k++]=a[i];
		}
	}
	for (int i=0;i<k;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct ss{
	char str[100];
	int num;
}a[105],b[105],c[105];
bool cmp(ss aa,ss bb){
	if (aa.num<bb.num)
		return true;
	return false;
}
int main(){
	int t,s,m,d;
	cin>>t;
	while (t--){
		cin>>s>>d>>m;
		for (int i=1;i<=s;i++){
			cin>>a[i].str>>a[i].num;
		}
		for (int i=1;i<=d;i++){
			cin>>b[i].str>>b[i].num;
		};
		for (int i=1;i<=m;i++){
			cin>>c[i].str>>c[i].num;
		}
		sort(a+1,a+s+1,cmp);
		sort(b+1,b+d+1,cmp);
		sort(c+1,c+m+1,cmp);
		
		int ans=a[s/2+1].num+b[d/2+1].num+c[m/2+1].num;
		cout<<ans<<" "<<a[s/2+1].str<<" "<<b[d/2+1].str<<" "<<c[m/2+1].str<<endl;
	}
	return 0;
}

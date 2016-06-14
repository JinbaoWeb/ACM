#include <bits/stdc++.h>
using namespace std;
bool used[600][600];
int main(){     
	int x,y,x0,y0;
	char str[100100];
	cin>>x>>y>>x0>>y0;
	cin>>str;
	int cnt=0;
	int ans=x*y-1;
	int len=strlen(str);
	memset(used,false,sizeof(used));
	for (int i=0;i<len;i++){
		if (str[i]=='U'){
			if (x0>1){
				cnt++;
				x0--;
			}
		}
		if (str[i]=='D'){
			if (x0<x){
				x0++;
				cnt++;
			}
		}
		if (str[i]=='R'){
			if (y0<y){
				y0++;
				cnt++;
			}
		}
		if (str[i]=='L'){
			if (y0>1){
				y0--;
				cnt++;
			}
		}
		if (!used[x0][y0]){
			used[x0][y0]=true;
			ans--;
			cout<<1<<" ";
		}
		else{
			cout<<0<<" ";
		}
	}
	cout<<ans<<endl;
  	return 0;
}
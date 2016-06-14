/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 19:39
 * Filename :        201505011939.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int n,l[1005];
void solve(){
	ll ans=0;
	priority_queue<int,vector<int>,greater<int> > que;
	for (int i=0;i<n;i++)
		que.push(l[i]);
	while (que.size()>1){
		int a,b;
		a = que.top();
		que.pop();
		b=que.top();
		que.pop();
		ans+=a+b;
		que.push(a+b);
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while (t--){

		cin>>n;
		for (int i=0;i<n;i++)
			cin>>l[i];
		solve();
	}
	return 0;
}

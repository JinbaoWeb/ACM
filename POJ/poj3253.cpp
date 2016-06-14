#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
#define MAX_N 20000+5
int N,L[MAX_N];
void solve(){
	ll ans=0;
	priority_queue< int, vector<int> , greater<int> > que;
	for (int i=0;i<N;i++)
		que.push(L[i]);
	while (que.size()>1){
		int l1,l2;
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();
		ans+=l1+l2;
		que.push(l1+l2);
	}
	cout<<ans<<endl;
}
int main(){
	while (cin>>N){
		for (int i=0;i<N;i++)
			cin>>L[i];
		solve();
	}
	return 0;	
}

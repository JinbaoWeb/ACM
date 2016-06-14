#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
#define MOD 1000000007
struct Node{
	int num,id;
};
int main(){
	int t,n;
	cin>>t;
	Node s,ss;
	while (t--){
		cin>>n;
		queue<Node> q;
		ll ans=1;
		while (!q.empty()){
			q.pop();
		}
		s.num=2,s.id=2;
		ss.num=2,ss.id=3;
		q.push(s);
		q.push(ss);
		while (!q.empty()){
			s=q.front();
			ans=(ans+s.num*s.id)%MOD;
			if (s.id==n)
				break;
			for (int i=0;i<s.num;i++){
				ss.num=s.id;
				ss.id=s.id+i+1;
				q.push(ss);
			}
			q.pop();
		}
		cout<<ans<<endl;
	}

	return 0;
}
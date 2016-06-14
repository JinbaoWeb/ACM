#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,l,p;
struct sl{
	int a,b;
}s[100005]; 
bool cmp(sl x,sl y){
	if (x.a<y.a)
		return true;
	return false;	
}
void solve(){
	s[n].a=l;
	s[n].b=0;
	n++;
	sort(s,s+n,cmp);
	priority_queue<int> que;
	int ans=0,pos=0,tank=p;
	for (int i=0;i<n;i++){
		
		int d=s[i].a-pos;
		while (tank-d<0){
			if (que.empty()){
				cout<<-1<<endl;
				return ;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}
		tank-=d;
		pos=s[i].a;
		que.push(s[i].b);
	}
	cout<<ans<<endl;
}
int main(){
	
	while (cin>>n){
		for (int i=0;i<n;i++)
			cin>>s[i].a>>s[i].b;
		cin>>l>>p;
		for(int i=0;i<n;i++)
			s[i].a=l-s[i].a;
		solve();
	}
	
	return 0;
}

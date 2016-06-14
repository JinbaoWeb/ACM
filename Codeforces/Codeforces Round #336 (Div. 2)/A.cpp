#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Node{
	int f,t;
}P[200];
bool cmp(Node a,Node b){
	if (a.f>b.f)
		return true;
	return false;
}
int main(){
	int n,s;
	cin>>n>>s;
	for (int i=0;i<n;i++){
		cin>>P[i].f>>P[i].t;
	}
	sort(P,P+n,cmp);
	int ans=0;
	for (int i=0;i<n;i++){
		ans+=s-P[i].f;
		if (ans<P[i].t)
			ans=P[i].t;
		s=P[i].f;
	}
	ans+=s;
	cout<<ans<<endl;
	return 0;
}




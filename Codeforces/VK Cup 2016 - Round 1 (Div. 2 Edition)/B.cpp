#include <bits/stdc++.h>
using namespace std;
set<int> s;
int a[150100];
int main(){
	int n,k,q;
	int x,id;
	cin>>n>>k>>q;
	set<int>::iterator it;
	s.clear();
	for (int i=0;i<n;i++)
		cin>>a[i];
	while (q--){
		cin>>x>>id;
		if (x==1){
			if (s.size()<k){
				s.insert(a[id-1]);
			}
			else{
				it=s.begin();
				if (a[id-1]>(*it)){
					s.erase(s.begin());
					s.insert(a[id-1]);
				}
			}
		}
		else{
			it=s.find(a[id-1]);
			
			if(it!=s.end())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
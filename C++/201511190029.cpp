#include <bits/stdc++.h>
using namespace std;
	bool check(vector <int> v){
		for (int i=1;i<v.size();i++){
			if (v[i]<v[i-1])
				return false;
		}
		return true;
	}
	int fl(vector <int> w){
		int flag=0;
		int l=0;
		while (check(w)==false){
			l++;
			if (flag==0)
				sort(w.begin(),w.end()-1);
			else
				sort(w.begin()+1,w.end());
			flag=(flag+1)%2;
		}
		return l;
	}
	int fr(vector <int> w){
		int flag=1,r=0;
		while (check(w)==false){
			r++;
			if (flag==0)
				sort(w.begin(),w.end()-1);
			else
				sort(w.begin()+1,w.end());
			flag=(flag+1)%2;
		}
		return r;
	}
	int minMoves(vector <int> w){
		int l=0,r=0;
		l=fl(w),r=fr(w);
		cout<<l<<" "<<r<<endl;
		if (l<r)
			return l;
		return r;
	}
int main(){
	int n;
	vector <int> w;
	bool a=false;
	if (a)
		cout<<1<<endl;
	cin>>n;
	for (int i=0;i<n;i++){
	int x;
		cin>>x;
		w.push_back(x);
	}
	cout<<minMoves(w)<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int p[60];
int t[60];
int main(){
	int n,c;
	cin>>n>>c;
	for (int i=0;i<n;i++)
		cin>>p[i];
	for (int i=0;i<n;i++)
		cin>>t[i];
	int x=0,y=0;	//Limak
	int t1=0,t2=0;
	for (int i=0;i<n;i++){
		t1+=t[i];
		int s=max(0,p[i]-t1*c);
		x+=s;
	}
	for (int i=n-1;i>=0;i--){
		t2+=t[i];
		int s=max(0,p[i]-t2*c);
		y+=s;
	}
	if (x>y)
		cout<<"Limak"<<endl;
	else if (x<y)
		cout<<"Radewoosh"<<endl;
	else
		cout<<"Tie"<<endl;
	return 0;
}
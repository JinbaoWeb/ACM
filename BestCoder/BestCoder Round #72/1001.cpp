#include <bits/stdc++.h>
using namespace std;
int A[30],B[30],C[30];
int main(){
	int t,a,b,c;
	char s;
	int num;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&a,&b,&c);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		for (int i=0;i<a;i++){
			cin>>s>>num;
			A[s-'A']=num;
		}
		for (int i=0;i<b;i++){
			cin>>s>>num;
			B[s-'A']=num;
		}
		for (int i=0;i<c;i++){
			cin>>s>>num;
			C[s-'A']=num;
		}
		int x,y;
		int flag;
		bool ans=false;
		for (x=1;x<100;x++){
			for (y=1;y<100;y++){
				flag=0;
				for (int z=0;z<30;z++){
					if (x*A[z]+y*B[z]!=C[z]){
						flag=1;
						break;
					}
				}
				if (flag==0){
					ans=true;
					break;
				}
			}
			if (ans==true)
				break;
		}
		if (ans==true)
			cout<<x<<" "<<y<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
char A[20],B[20];
int main()
{
	int a,b;
	while (cin>>A>>a>>B>>b){
		int lenA=strlen(A),lenB=strlen(B);
		int x=0,y=0;
		for (int i=0;i<lenA;i++){
			if (A[i]-'0'==a){
				x++;
			}
		}
		for (int i=0;i<lenB;i++){
			if (B[i]-'0'==b){
				y++;
			}
		}
		long long ans1=0,ans2=0;
		while (x){
			ans1=ans1*10+a;
			x--;
		}
		while (y){
			ans2=ans2*10+b;
			y--;
		}
		cout<<x+y<<endl;
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int num[40];
int num2[40];
int k;
int f(int x){
	k=0;
	int tmp=0;
	while (x){
		num[k++]=x%2;
		if (num[k-1]==1)
			tmp++;
		x/=2;
	}
	return tmp;
}
int Count(int n) { 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ;
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ;
    n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ;
    n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ;
    return n ; 
}
int main(){
	int t,d,s1,s2;
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		memset(num,0,sizeof(num));
		memset(num2,0,sizeof(num2));
		scanf("%d%d%d",&d,&s1,&s2);
		printf("Case #%d: ",cas);
		int cnt=f(d);
		if (cnt<s1){
			int res=s1-cnt;
			for (int i=0;i<res;i++){
				for (int j=0;j<k;j++){
					if (num[j]==0){
						num[j]=1;
						break;
					}
				}
			}
			int ans=0;
			for (int i=k-1;i>=0;i--)
				ans=ans*2+num[i];
			cout<<ans<<endl;
		}
		else{
			int index=-1;
			for (int i=0;;i++){
				if (num[i]==1 && num[i+1]==0){
					index=i;
					num[i]=0;
					num[i]=1;
					break;
				}
			}
			int count=0;

			for (int i=k-1;i>=index;i--){
				if (num[i]==1)
					count++;
			}
			cout<<"-------"<<count<<endl;
			if (count>=s1){
				int res=0;
				for (int i=k-1;i>=0;i--){
					if (res>=s1){
						num[i]=0;
					}
					if (num[i]==1)
						res++;
				}
			}
			else{
				cout<<2<<endl;
				for (int i=index;i>=0;i--){
					num[i]=0;
				}
				for (int i=0;i<s1-count;i++)
					num[i]=1;
			}
			for (int i=0;i<k+3;i++)
				cout<<num[i];
			cout<<endl;
			int ans=0;
			for (int i=k-1;i>=0;i--)
				ans=ans*2+num[i];
			cout<<ans<<endl;
		}
}
	return 0;
}
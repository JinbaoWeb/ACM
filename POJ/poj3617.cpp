#include <iostream>
using namespace std;
bool f(char *s,int i,int j){
	for (int x=i,y=j;x<=y;x++,y--){
		if (s[x]<s[y])
			return true;
		if (s[x]>s[y])
			return false;
	}
	return true;
}
int main(){
	int n;
	char s[2005],a[200];
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>s[i];
		}
		int k=0,i=0,j=n-1;
		while (i<=j){
			if (f(s,i,j)==true)
				a[k++]=s[i++];
			else
				a[k++]=s[j--];	
		}
		
		for (int p=0;p<k;p++){	
			if (p%80==0&p)
				cout<<endl;
			cout<<a[p];
		}
		if ((k-1)%80)
			cout<<endl;
	}
	return 0;
} 

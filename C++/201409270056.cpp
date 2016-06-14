#include <iostream>
using namespace std;
#define M 2005
int main(){
	int n,h[M],index[M];
	while (cin>>n){
		for (int i=0;i<n;i++){
			index[i]=i;
			cin>>h[i];
		}
		int count=0,flag=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				if (h[i]==h[j])
					count++;
				if (count>=2){
					flag=1;
					break;
				}
			}
			if (flag)
				break;
		}	
		if (flag){
			cout<<"YES"<<endl;
			int num=0;
			int p[4],k=0;
			for (int i=0;i<n;i++){
				for (int j=i+1;j<n;j++){
					if (h[i]==h[j]){
						p[k++]=i;
						p[k++]=j;
						break;
					}
				}
				if (k==5)
					break;
			}
			cout<<p[0]<<"-"<<p[1]<<"-"<<p[2]<<"-"<<p[3]<<endl;
			
			index[p[0]]=p[1];
			index[p[1]]=p[0];
			for (int i=0;i<n-1;i++)
				cout<<index[i]+1<<" ";
			cout<<index[n-1]+1<<endl;
			index[p[0]]=p[0];
			index[p[1]]=p[1];	
			
			
				
			index[p[2]]=p[3];
			index[p[3]]=p[2];
			for (int i=0;i<n-1;i++)
				cout<<index[i]+1<<" ";
			cout<<index[n-1]+1<<endl;
			index[p[2]]=p[2];
			index[p[3]]=p[3];
			
			index[p[0]]=p[1];
			index[p[1]]=p[0];
			index[p[2]]=p[3];
			index[p[3]]=p[2];
			for (int i=0;i<n-1;i++)
				cout<<index[i]+1<<" ";
			cout<<index[n-1]+1<<endl;
			index[p[0]]=p[0];
			index[p[1]]=p[1];
			index[p[2]]=p[2];
			index[p[3]]=p[3];
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int t,n;
	char s1[220],s2[220],temp[220],s[1000][220];
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n;
		for (int i=0;i<n*2;i++)
			cin>>s1[i];
		s1[2*n]=0;
		cin>>s2;
		int k=0,flag=0,count=0;
		while (strcmp(s1,s2)!=0){
			cout<<"--------"<<endl;
			cout<<s1<<endl;
			cout<<s2<<endl;
			cout<<"--------"<<endl;		
			for (int i=0;i<k;i++){
				if (strcmp(s[i],s1)==0){
					flag=1;
					break;
				}
			}
			if (flag==1)
				break;
			strcpy(s[k++],s1);
			for (int i=0;i<n*2;i++){
				if (i%2==0)
					temp[i]=s1[(i/2)%n];
				else
					temp[i]=s1[(i+1)/2+n-1];
			}
			temp[2*n]=0;
			strcpy(s1,temp);
			count++;
		}
		if (flag==0)
			cout<<cas<<" "<<count<<endl;
		else
			cout<<cas<<" "<<-1<<endl;
	}
	return 0;
}
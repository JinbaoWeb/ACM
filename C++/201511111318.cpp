#include <bits/stdc++.h>
using namespace std;
char s1[10],s2[10],s3[10];
bool used[5];
int dfs(int k,int x,int y,int z){
	if (used[k]==true){
		for (int i=0;i<10;i++){
		}
	}
}
int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>s1>>s2>>s3;
		int len1=strlen(s1),len2=strlen(s2),len3=strlen(s3);
		memset(used,false,sizeof(used));
		for (int i=0;i<len1;i++){
			used[s1[i]-'A']=true;
		}
		for (int i=0;i<len2;i++){
			used[s2[i]-'A']=true;
		}
		for (int i=0;i<len3;i++){
			used[s3[i]-'A']=true;
		}
		int ans=0;
		int cnt=0;
		for (int a=0;a<=9;a++){
			for (int b=0;b<=9;b++){
				if (a==b)
					continue;
				for (int c=0;c<=9;c++){
					if (a==c || b==c)
						continue;
					for (int d=0;d<=9;d++){
						if (d==a || d==b || d==c)
							continue;
						for (int e=0;e<=9;e++){
							if (e==a || e==b || e==c || e==d)
								continue;
							int x=0,y=0,z=0;
							//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
							cnt++;
							/*
							if (used[0]==false)
								a=-1;
							if (used[1]==false)
								b=-1;
							if (used[2]==false)
								c=-1;
							if (used[3]==false)
								d=-1;
							if (used[4]==false)
								e=-1;
								*/
							for (int i=0;i<len1;i++){
								int temp=0;
								if (s1[i]=='A')
									temp=a;
								if (s1[i]=='B')
									temp=b;
								if (s1[i]=='C')
									temp=c;
								if (s1[i]=='D')
									temp=d;
								if (s1[i]=='E')
									temp=e;
								x=x*10+temp;
							}
							for (int i=0;i<len2;i++){
								int temp=0;
								if (s2[i]=='A')
									temp=a;
								if (s2[i]=='B')
									temp=b;
								if (s2[i]=='C')
									temp=c;
								if (s2[i]=='D')
									temp=d;
								if (s2[i]=='E')
									temp=e;
								y=y*10+temp;
							}
							for (int i=0;i<len3;i++){
								int temp=0;
								if (s3[i]=='A')
									temp=a;
								if (s3[i]=='B')
									temp=b;
								if (s3[i]=='C')
									temp=c;
								if (s3[i]=='D')
									temp=d;
								if (s3[i]=='E')
									temp=e;
								z=z*10+temp;
							}
							if (a==1)
								cout<<x<<" "<<y<<" "<<z<<endl;
							//cout<<x<<" "<<y<<" "<<z<<endl;
							if (x+y==z)
								ans++;
							if (x-y==z)
								ans++;
							if (x*y==z)
								ans++;
							if (y && x%y==0 && x/y==z)
								ans++;
							
						}
					}
				}
			}
		}
		cout<<cnt<<" "<<ans<<endl;
	}
	return 0;
}
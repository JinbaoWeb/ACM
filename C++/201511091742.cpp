#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	char name[40];
	int v;
	int i;
}g[1000],d[1000],m[1000],s[1000];
struct Node2{
	char pos1[20],pos2[20];
	int v;
}p[1000];
int g1,d1,m1,s1;
int main(){
	char name[30][40],pos[30][20];
	int v[30];
	while (~scanf("%s%d%s",name[0],&v[0],pos[0])){
		g1=0,d1=0,m1=0,s1=0;
		if (pos[0][0]=='g'){
			strcpy(g[g1].name,name[0]);
			g[g1].v=v[0];
			g[g1].i=0;
			g1++;
		}
		if (pos[0][0]=='d'){
			strcpy(d[d1].name,name[0]);
			d[d1].v=v[0];
			d[d1].i=0;
			d1++;
		}
		if (pos[0][0]=='m'){
			strcpy(m[m1].name,name[0]);
			m[m1].v=v[0];
			m[m1].i=0;
			m1++;
		}
		if (pos[0][0]=='s'){
			strcpy(s[s1].name,name[0]);
			s[s1].v=v[0];
			s[s1].i=0;
			s1++;
		}
		for (int i=1;i<23;i++){
			scanf("%s%d%s",name[i],&v[i],pos[i]);
			if (pos[i][0]=='g'){
				strcpy(g[g1].name,name[i]);
				g[g1].v=v[i];
				g[g1].i=i;
				g1++;
			}
			if (pos[i][0]=='d'){
				strcpy(d[d1].name,name[i]);
				d[d1].v=v[i];
				d[d1].i=i;
				d1++;
			}
			if (pos[i][0]=='m'){
				strcpy(m[m1].name,name[i]);
				m[m1].v=v[i];
				m[m1].i=i;
				m1++;
			}
			if (pos[i][0]=='s'){
				strcpy(s[s1].name,name[i]);
				s[s1].v=v[i];
				s[s1].i=i;
				s1++;
			}
		}
		int n;
		cin>>n;
		int cnt[30][30];
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++){
			scanf("%s%s%d",p[i].pos1,p[i].pos2,&p[i].v);
			int l ,r;
			for (int j=0;j<23;j++){
				if (strcmp(name[j],p[i].pos1)==0)
					l=j;
				if (strcmp(name[j],p[i].pos2)==0)
					r=j;
			}
			cnt[l][r]=p[i].v;
			cnt[r][l]=p[i].v;
		}
		//cout<<g1<<" "<<d1<<" "<<m1<<" "<<s1<<endl;
		if (g1<1 || d1<4 || m1<4 || s1<2){
			cout<<"impossible"<<endl;
			continue;
		}
		bool temp[30];
		memset(temp,false,sizeof(temp));
		//---------------------------------
		int Max=-0xfffffff;
		for (int j=0;j<g1;j++){
			temp[g[j].i]=true;
			//strcpy(ss[0],g[j].name);
			//-----------------------------
			for (int j1=0;j1<d1;j1++){
				temp[d[j1].i]=true;
				//strcpy(ss[1],d[j1].name);
				for (int j2=j1+1;j2<d1;j2++){
					temp[d[j2].i]=true;
					//strcpy(ss[2],d[j2].name);
					for (int j3=j2+1;j3<d1;j3++){
						temp[d[j3].i]=true;
						//strcpy(ss[3],d[j3].name);
						for (int j4=j3+1;j4<d1;j4++){
							temp[d[j4].i]=true;
							//strcpy(ss[4],d[j4].name);
							//-----------------------------
							for (int j5=0;j5<m1;j5++){
								temp[m[j5].i]=true;
								//strcpy(ss[5],m[j5].name);
								for (int j6=j5+1;j6<m1;j6++){
									temp[m[j6].i]=true;
									//strcpy(ss[6],m[j6].name);
									for (int j7=j6+1;j7<m1;j7++){
										temp[m[j7].i]=true;
										//strcpy(ss[7],m[j7].name);
										for (int j8=j7+1;j8<m1;j8++){
											temp[m[j8].i]=true;
											//strcpy(ss[8],m[j8].name);
											//---------------------------------
											for (int j9=0;j9<s1;j9++){
												temp[s[j9].i]=true;
												//strcpy(ss[9],s[j9].name);
												for (int j10=j9+1;j10<s1;j10++){
													temp[s[j10].i]=true;
													//strcpy(ss[10],s[j10].name);
													int ans=g[j].v+d[j1].v+d[j2].v+d[j3].v+d[j4].v+m[j5].v+m[j6].v+m[j7].v+m[j8].v+s[j9].v+s[j10].v;
													for (int iii=0;iii<=23;iii++){
														if (temp[iii]==false)
															continue;
														for (int ii=iii+1;ii<=23;ii++){
															if (temp[ii]==false)
																continue;
															ans+=cnt[iii][ii];
														}
													}
													/*
													for (int i=0;i<11;i++){
														for (int ii=i+1;ii<11;ii++){
															int l,r;
															for (int kk=0;kk<23;kk++){
																if (strcmp(ss[i],name[kk])==0){
																	l=kk;
																}
																if (strcmp(ss[ii],name[kk])==0){
																	r=kk;
																}
															}
															ans+=cnt[l][r];
														}
													}
													*/
													Max=max(Max,ans);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<Max<<endl;
	}
	return 0;
}
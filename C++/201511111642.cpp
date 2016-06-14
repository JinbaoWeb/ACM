#include <bits/stdc++.h>
using namespace std;
const int M=6000010;
char word[300][1010];
char str[M],str1[M],str2[M];
int Next[M];
void get_next(char* p, int* Next)
{
	int i, j;
	i = 0;
	j = -1;
	Next[0] = -1;
	while (i < strlen(p))
	{
		if (j == -1 || p[i] == p[j])
		{
			i++;
			j++;
			//next[i] = j;
			
			if (p[i] != p[j])
			Next[i] = j;
			else
			Next[i] = Next[j];
			
			//cout << "next[i] = " << j << endl;
		}
		else
		{
			j = Next[j];
			//cout << "i = " << i << " j = " << j << endl;
		}
	}
}

int index_kmp(char* p, char* x)
{
	int i = -1;
	int j = -1;
	int len1 = strlen(p);
	int len2 = strlen(x);
	get_next(x, Next);
	while(i < len1 && j < len2)
	{
		if (j == -1 || p[i] == x[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Next[j];
			//cout << "i = " << i << " j = " << j << endl;
		}
	}
	if (j == strlen(x))
		return i - strlen(x);
	else
		return -1;
}
void Change(char *s){
    int len=strlen(s);
    int j=0,q;
    for(int i=0;i<len;i++){
        if(str[i]==']')
            continue;
        if(s[i]=='['){
            i++;
            q=0;
            while(s[i]>='0' && s[i]<='9'){
                q=q*10+s[i]-'0';
                i++;
            }
            while(q--)
                str1[j++]=s[i];
        }else
            str1[j++]=s[i];
    }
    str1[j]='\0';
    for(int i=0;i<j;i++)
        str2[i]=str1[j-1-i];
    str2[j]='\0';
}
int main(){
	int t,n;
	cin>>t;
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%s",word[i]);
			//cin>>word[i];
		scanf("%s",str);
		//cin>>str;
		Change(str);
		//cout<<str1<<endl;
		//cout<<str2<<endl;
		int ans=0;
		for (int i=0;i<n;i++){
			if (index_kmp(str1,word[i])!=-1 || index_kmp(str2,word[i])!=-1)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
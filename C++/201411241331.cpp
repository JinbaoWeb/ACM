#include<iostream>
using namespace std;
#define N 105
#define INF 1e9
int d[N][N];
int pos[N][N];
char s[N];  //接受初始数据
void Match(int len)
{
 int i,j,k;
 for(i=0;i<len;i++)
  d[i][i]=1;
 for(k=1;k<len;k++)   //表示i和j之间的间隔
  for(i=0;i<len-k;i++)
  {
   char right=s[i+k];
   char left=s[i];
   d[i][i+k]=INF;  //此条语句不能少，假如下面的if不执行，则for中判断就会出错d[i][i+k]未赋值
   if(left=='('&&right==')'||left=='['&&right==']')
   {
    d[i][i+k]=d[i+1][i+k-1];
    pos[i][i+k]=-1;
   }
   for(j=i;j<i+k;j++) //靠左分界
    if(d[i][i+k]>d[i][j]+d[j+1][i+k])
    {
     pos[i][i+k]=j;
     d[i][i+k]=d[i][j]+d[j+1][i+k];
    }
  }
}
void show(int i,int j)
{
 if(i>j)  return;
 if(i==j)
 {
  if(s[i]=='('||s[i]==')') cout<<"()";
  else      cout<<"[]";
 }
 else
 {
  if(pos[i][j]==-1)
  {
   cout<<s[i];
   show(i+1,j-1);
   cout<<s[j];
  }
  else
  {
   show(i,pos[i][j]);
   show(pos[i][j]+1,j);
  }
 }
}
int main()
{  
 cin>>s;
 int len=strlen(s);
 Match(len);
 show(0,len-1);
 cout<<endl;
 return 0;
}
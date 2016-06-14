#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500000+10;
ll n,a[MAXN],b[MAXN],c[MAXN];
int main()
{
  cin>>n;
  memset(c,0,sizeof(c));
  for(int i=1;i<=n;i++)
    cin>>a[i];
  b[1]=a[1];
  b[n]=a[n];
  int i=2;
  for(;i<=n-1;i++){
    if(a[i]!=a[i-1] && a[i]!=a[i+1]){
	  	b[i]=b[i-1];
	  	c[i]=c[i-1]+1;
	}
    else
		b[i]=a[i];
  }
  i=n;
  while (i--){
     if(a[i]!=a[i-1] && a[i]!=a[i+1] && c[i]>c[i+1]+1)
	{
	  b[i]=b[i+1];
	  c[i]=c[i+1]+1;
	}
   }
  ll Max=-1;
  for(int i=1;i<=n;i++)
    Max=max(Max,c[i]);
  cout<<Max<<endl;
  for(int i=1;i<n;i++)
    cout<<b[i]<<" ";
   cout<<b[n]<<endl;
  return 0;
}
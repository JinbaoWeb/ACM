#include <iostream>
using namespace std;
int main()
{
	int N,n,t[305],w[305];
	for (int i=1;i<305;i++)
		t[i]=(i+1)*i/2;
	w[0]=0;
	for (int i=1;i<302;i++)
		w[i]=i*t[i+1]+w[i-1];
	cin>>N;
	for (int c=1;c<=N;c++)
	{
		cin>>n;
		cout<<c<<" "<<n<<" "<<w[n]<<endl;
	}
	return 0;
}

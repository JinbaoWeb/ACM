#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
using namespace std;

char ch[11];

void fileBegin(int fileID){
    sprintf(ch, "%d.in", fileID);
    freopen(ch, "w", stdout);
}

int main()
{
	int id = 0;
	srand(time(NULL));
	fileBegin(id++);
	cout<<100<<endl;
	for(int i=1;i<=100;i++)
	{
		int n=rand()%20000+1;
		cout<<n<<endl;
		for(int j=1;j<n;j++)
			cout<<rand()%100000+1<<" ";
		cout<<rand()%100000+1<<endl;
	}
	fclose(stdout);
	return 0;
}
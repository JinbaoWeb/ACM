#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char key[100],message[200];
	while (cin.getline(key,100))
	{
		cin.getline(message,200);
		int len=strlen(message);
		for (int i=0;i<len;i++)
		{
			if (message[i]<='Z'&&message[i]>='A')
				message[i]=key[message[i]-'A']+'A'-'a';
			if (message[i]<='z'&&message[i]>='a')
				message[i]=key[message[i]-'a'];
		}
		cout<<message<<endl;
	}
	return 0;
}

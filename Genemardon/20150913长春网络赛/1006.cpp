#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
string biggest(string s, int &ans)
{
	int i, j, k, l;
	int N = s.length();
	s += s;
	for(i = 0, j = 1;j < N;)
	{
		for(k = 0;k < N && s[i+k] == s[j+k];k++);
		if(k >= N)
			break;
		if(s[i+k] > s[j+k])
			j += k+1;
		else
		{
			l = i+k;
			i = j;
			j = max(l, j) + 1;
		}
	}
	ans = i;
	return s.substr(i, N);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		cin >> s;
		int ans;
		string sub = biggest(s, ans);
		cout << sub << endl;
	}
	return 0;
}
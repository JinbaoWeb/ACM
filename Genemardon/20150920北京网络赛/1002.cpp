#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
char str[10010];
string ans, cup;
int caret, n, swit, copys, cs;
void play(char c)
{
	int len = ans.length();
	string left = ans.substr(0, caret);
	string right = ans.substr(caret, len-caret);
	if(c >= 'a' && c <= 'z')
	{
		copys = 0;
		if(swit == 0 && len < n)
		{
			ans = left+c+right;
			caret++;
		}
		else if(swit == 1)
		{
			if(caret == len && len < n)
			{
				ans = ans+c;
				caret++;
			}
			else if(caret < len)
			{
				ans[caret] = c;
				caret++;
			}
		}
	}
	else if(c == 'L' && caret > 0)
		caret--;
	else if(c == 'R' && caret < len)
		caret++;
	else if(c == 'S')
	{
		copys = 0;
		swit = 1-swit;
	}
	else if(c == 'D')
	{
		if(copys == 1)
		{
			if(caret != cs)
			{
				int L = min(cs, caret), R = max(cs, caret);
				ans = ans.substr(0, L)+ans.substr(R,len-R);
				caret = L;
			}
			copys = 0;
		}
		else if(caret < len)
			ans = left+ans.substr(caret+1, len-caret-1);
	}
	else if(c == 'B' && caret > 0)
	{
		copys = 0;
		ans = ans.substr(0, caret-1)+right;
		caret--;
	}
	else if(c == 'C')
	{
		if(copys == 0)
			cs = caret;
		else
			cup = cs < caret? ans.substr(cs, caret-cs):ans.substr(caret, cs-caret);
		copys = 1-copys;
	}
	else if(c == 'V')
	{
		copys = 0;
		if(swit == 0)
		{
			if(left.length()+cup.length()+right.length() > n)
				return;
			ans = left+cup+right;
		}
		else
		{
			if(cup.length() >= right.length())
			{
				if(left.length()+cup.length() > n)
					return;
				ans = left + cup;
			}
			else
				ans = left + cup + right.substr(cup.length(), right.length()-cup.length());
		}
		caret += cup.length();
	}
	/*if(caret == 0)
		printf("NOTHING");
	cout << ans << " " << caret <<" " << cs << " " << cup << endl;*/
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &n, &str);
		ans = "";
		cup = "";
		swit = copys = caret = cs = 0;
		int strl = strlen(str);
		for(int i = 0;i < strl;i++)
			play(str[i]);
		if(ans.length() == 0)
			printf("NOTHING\n");
		else
			cout << ans << endl;
		//printf("---------\n");
	}
	return 0;
}
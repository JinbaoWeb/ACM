#include <bits/stdc++.h>
using namespace std;

template <class T>
void PT(T a) {
     if(a > 9) PT(a / 10);
     putchar(a % 10 + '0');
}

const int MOD = 1000000000 + 7;
typedef __int64 LL;
int num[100];
char op[100];

vector<int> calc(int l, int r) {
    vector<int> ret;
    if(l >= r) {
        ret.push_back(num[l]);
        return ret;
    }
    for(int i = l; i < r; i++) {
        char ch = op[i];
        if(ch == '+' || ch == '-' || ch == '*') {
            vector<int> lv = calc(l, i);
            vector<int> rv = calc(i + 1, r);
            for(auto x : lv) {
                for(auto y : rv) {
                    if(ch == '+')
                        ret.push_back(x + y + MOD % MOD);
                    else if(ch == '*')
                        ret.push_back(x * y + MOD % MOD);
                    else if(ch == '-')
                        ret.push_back(x - y + MOD % MOD);
                }
            }
        }
    }
    return ret;
}

int main() {
    //freopen("1001.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)) {
        string s;
        for(int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        scanf("%s", op);
        vector<int> tmp = calc(0, n - 1);
        LL ans = 0;
        for(int i = 0; i < tmp.size(); i++) {
            ans += tmp[i] + MOD;
            ans %= MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
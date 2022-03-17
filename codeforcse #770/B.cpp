#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define fr first
#define se second
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int,int> PII;
const int N = 100010, INF = 0x3f3f3f3f, mod = 1e9 + 7;
inline LL gcd(LL a, LL b){  return a%b?gcd(b,a%b):b; }
inline LL qmi(LL a, LL b){LL res = 1;for(; b; b >>= 1){if(b & 1) res = res * a % mod;a = a * a % mod;}return res;}
int T;

void solve()
{
    LL n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i ++ )
    {
        int t;
        cin >> t;
        x ^= t;
    }
    if((x & 1) == (y & 1)) cout << "Alice\n";
    else cout << "Bob\n";
}

int main(void)
{
    clock_t c1 = clock();ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("/home/yzzlqyxc/ACM/in.in", "r", stdin);
    freopen("/home/yzzlqyxc/ACM/out.out", "w", stdout);
#endif

    T = 1;
    cin >> T;
    while(T -- )
        solve();

#ifndef ONLINE_JUDGE
    cerr << "Time Used:" << clock() - c1 << "ms" << '\n';
#endif
    return 0;
}

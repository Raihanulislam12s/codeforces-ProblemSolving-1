#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define dep(i, l, r) for (int i = r; i >= l; --i)
const int N = 1e5 + 5;
const int Mod = 998244353;
int n, m, x, ans, a[N], p[N], pw[N], ipw[N];

int inc (int a, int b) { return (a += b) >= Mod ? a - Mod : a; }
int dec (int a, int b) { return (a -= b) < 0 ? a + Mod : a; }
int mul (int a, int b) { return 1ll * a * b % Mod; }
int fpow (int a, int b) { int ans = 1; for ( ; b; a = mul(a, a), b >>= 1) if(b & 1) ans = mul(ans, a); return ans; }

int main () {
  scanf("%d%d", &n, &m);
  rep(i, 1, n) scanf("%d", &a[i]);
  rep(i, 1, m) scanf("%d", &x), p[x] = 1;
  pw[0] = 1; rep(i, 1, n) pw[i] = mul(pw[i - 1], 2);
  ipw[0] = 1, ipw[1] = fpow(2, Mod - 2);
  rep(i, 2, n) ipw[i] = mul(ipw[i - 1], ipw[1]);
  rep(i, 1, n) {
    int res = p[i]; long long cur = ipw[res];
    if(i <= n / 2) {
      int j = 1;
      for (j = 1; j + 7 < i; ++j) {
        res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
      }
      for ( ; j < i; ++j) res += p[i + j] + p[i - j], cur += ipw[res];
      for ( ; j + 7 <= n - i; ++j) {
        res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
        ++j, res += p[i + j], cur += ipw[res];
      }
      for ( ; j <= n - i; ++j) res += p[i + j], cur += ipw[res];
    } else {
      int j = 1;
      for (j = 1; j + 7 <= n - i; ++j) {
        res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
        ++j, res += p[i + j] + p[i - j], cur += ipw[res];
      }
      for ( ; j <= n - i; ++j) res += p[i + j] + p[i - j], cur += ipw[res];
      for ( ; j + 7 < i; ++j) {
        res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
        ++j, res += p[i - j], cur += ipw[res];
      }
      for ( ; j < i; ++j) res += p[i - j], cur += ipw[res];
    }
    cur %= Mod;
    ans = inc(ans, mul(dec(mul(cur, pw[m]), max(n - i + 1, i)), a[i]));
  }
  ans = mul(ans, fpow(dec(pw[m], 1), Mod - 2));
  printf("%d", ans);
  return 0;
}

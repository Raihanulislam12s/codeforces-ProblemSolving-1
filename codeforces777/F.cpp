#include "bits/stdc++.h"
#ifdef LOCAL
  #include "local/debug.hpp"
#else
  #define debug(...)
#endif
using namespace std;

constexpr int INF = 1e9 + 7;

int n;

int solve(const vector<int> &a) {
  int id = (int)(max_element(a.begin(), a.end()) - a.begin());
  int mx[2] = {};
  for (int i = 0; i <= id; ++i) {
    if (a[i] > mx[0]) {
      mx[0] = a[i];
    } else if (a[i] > mx[1]) {
      mx[1] = a[i];
    } else {
      return 0;
    }
  }
  int mx0 = mx[1];
  vector<int> suff(n, INF);
  mx[0] = mx[1] = 0;
  for (int i = n - 1; i > id; --i) {
    if (a[i] > mx[0]) {
      mx[0] = a[i];
      suff[i] = mx[1];
    } else if (a[i] > mx[1]) {
      mx[1] = a[i];
      suff[i] = mx[0];
    } else {
      break;
    }
  }
  int ans = 0;
  array<int, 2> dp = {mx0, 0};
  for (int i = id + 1; i < n; ++i) {
    array<int, 2> new_dp = {INF, 0};
    if (a[i] < a[i - 1]) {
      new_dp[0] = min(new_dp[0], dp[0]);
    }
    if (a[i] > a[i - 1]) {
      new_dp[1] = max(new_dp[1], dp[1]);
    }
    if (a[i] < dp[1]) {
      new_dp[0] = min(new_dp[0], a[i - 1]);
    }
    if (a[i] > dp[0]) {
      new_dp[1] = max(new_dp[1], a[i - 1]);
    }
    dp = new_dp;
    if (dp[1] > suff[i]) {
      ans++;
    }
  }
  return ans;
}

void MAIN() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  ans += solve(a);
  reverse(a.begin(), a.end());
  ans += solve(a);
  cout << ans << '\n';
}

signed main() {
  #ifndef LOCAL
    std::ios_base::sync_with_stdio(false);
    std::cin.exceptions(std::cin.failbit);
    std::cin.tie(0);
  #endif
  MAIN();
  #ifdef LOCAL
    std::clog << "\nTime elapsed: " << std::fixed << std::setprecision(4) << float(clock()) / CLOCKS_PER_SEC << " seconds.";
  #endif
}

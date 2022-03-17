#include <bits/stdc++.h>

using namespace std;
#define int long long

#ifdef LOCAL
#include "prettyprint.h"
#else
#define deb(...)
#endif

void solve() {
  int x, d; cin >> x >> d;
  int X = x;

  int cnt = 0;
  while(x % d == 0) {
    x /= d;
    cnt++;
  }

  if(cnt < 2) {
    cout << "NO\n";
    return;
  }

  auto good = [&](int number) -> bool {
    if(number % d == 0) return true;
    else return false;
  };

  auto beautiful = [&](int number) -> bool {
    for(int i = 1; i * i <= number; i++) {
      if(number % i == 0) {
        int other = number / i;
        if(good(i) && good(other)) {
          return false;
        }
      }
    }
    return true;
  };

  auto prime = [&](int number) -> bool {
    for(int i = 2; i * i <= number; i++) {
      if(number % i == 0) return false;
    }
    return true;
  };

  if(beautiful(X)) {
    cout << "YES\n";
    return;
  }

  map<int, int> facts;
  for(int i = 2; i * i <= x; i++) {
    while(x % i == 0) {
      x /= i;
      facts[i]++;
    }
  }

  if(x > 1) {
    facts[x]++;
  }

  int pows = 0;
  for(auto xx : facts) {
    pows += (xx.second);
  }

  if(pows > 1) {
    cout << "YES\n";
    return;
  }

  if(cnt > 2) {
    if(cnt > 3 && !prime(d)) {
      cout << "YES\n";
      return;
    }
    for(int i = 2; i * i <= d; i++) {
      if(d % i == 0) {
        if(!facts.count(i) || !facts.count(d / i)) {
          cout << "YES\n";
          return;
        }
      }
    }
  }

  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve();
  }
}


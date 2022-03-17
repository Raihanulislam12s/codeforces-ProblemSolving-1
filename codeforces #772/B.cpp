#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 4e5 + 5;

int n, a[N], T;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(6);
#ifdef LOCAL
    clock_t c1 = clock();
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    // =================================================
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        int ans = 0; a[n + 1] = 0;
        for (int i = 2; i <= n - 1; i ++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                ans ++, a[i + 1] = max (a[i + 2], a[i]);
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i ++)
            cout << a[i] << ' ';
        cout << endl;
    }
    // =================================================
#ifdef LOCAL
    cerr << "Time Used = " << clock() - c1 << "ms" << endl;
#endif
    return 0;
}

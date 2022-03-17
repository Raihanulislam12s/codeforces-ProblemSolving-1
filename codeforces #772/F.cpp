#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 3e5+10;
const int base = 31337;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;

int n, q;
int x[maxn], y[maxn];
vector< pair<int, int> > qs[maxn];
llint sol[maxn];
llint tour[treesiz];
pair<int, llint> l[maxn], r[maxn];
vector< int > ps[maxn];

inline llint calc(int a, int b) {
	return (llint)abs(x[a] - x[b]) * (y[a] + y[b]);
}

void update(int x, llint val) {
	x += off;
	tour[x] = min(tour[x], val);

	x /= 2;
	while (x > 0) tour[x] = min(tour[x * 2], tour[x * 2 + 1]), x /= 2;
}

llint query(int a, int b, int l, int r, int node) {
	if (l > b || r < a) return (1LL << 62);
	if (l >= a && r <= b) return tour[node];

	int mid = (l + r) / 2;
	return min(query(a, b, l, mid, node * 2), query(a, b, mid + 1, r, node * 2 + 1));
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x+i, y+i);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r); l--, r--;
		qs[r].push_back({l, i});
	}

	stack< int > s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && y[s.top()] > y[i]) s.pop();
		if (s.empty()) l[i] = {-1, -1};
		else l[i] = {s.top(), calc(s.top(), i)};
		s.push(i);
	}

	while (!s.empty()) s.pop();
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && y[s.top()] > y[i]) s.pop();
		if (s.empty()) r[i] = {-1, -1};
		else {
			r[i] = {s.top(), calc(s.top(), i)};
			ps[s.top()].push_back(i);
		}
		s.push(i);
	}

	for (int i = 0; i < treesiz; i++) tour[i] = (1LL << 62);
	for (int i = 0; i < n; i++) {
		if (l[i].X != -1) update(l[i].X, l[i].Y);
		for (int j = 0; j < ps[i].size(); j++)
			update(ps[i][j], r[ps[i][j]].Y);

		for (auto tren : qs[i])
			sol[tren.Y] = query(tren.X, i, 0, off - 1, 1);
	}
	for (int i = 0; i < q; i++)
		printf("%lld\n", sol[i]);
	return 0;
}

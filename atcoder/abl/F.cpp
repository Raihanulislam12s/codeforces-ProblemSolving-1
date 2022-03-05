#include<bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
const int mod = 998244353;
const int root = 3;
int lim, rev[N], w[N], wn[N], inv_lim;
void reduce(int &x) { x = (x + mod) % mod; }
int POW(int x, int y, int ans = 1) {
	for (; y; y >>= 1, x = (long long) x * x % mod) if (y & 1) ans = (long long) ans * x % mod;
	return ans;
}
void precompute(int len) {
	lim = wn[0] = 1; int s = -1;
    while (lim < len) lim <<= 1, ++s;
	for (int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
	const int g = POW(root, (mod - 1) / lim);
	inv_lim = POW(lim, mod - 2);
	for (int i = 1; i < lim; ++i) wn[i] = (long long) wn[i - 1] * g % mod;
}
void ntt(vector<int> &a, int typ) {
	for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		for (int j = 0, t = lim / i / 2; j < i; ++j) w[j] = wn[j * t];
		for (int j = 0; j < lim; j += i << 1)
			for (int k = 0; k < i; ++k) {
				const int x = a[k + j], y = (long long) a[k + j + i] * w[k] % mod;
				reduce(a[k + j] += y - mod), reduce(a[k + j + i] = x - y);
			}
	}
	if (!typ) {
        reverse(a.begin() + 1, a.begin() + lim);
		for (int i = 0; i < lim; ++i) a[i] = (long long) a[i] * inv_lim % mod;
	}
}
vector<int> multiply(vector<int> f, vector<int> g) {
    if (f.size() > 100000) f.resize(100001);
    if (g.size() > 100000) g.resize(100001);
    int n=(int)f.size() + (int)g.size() - 1;
    precompute(n);
    vector<int> a = f, b = g;
    a.resize(lim); b.resize(lim);
    ntt(a, 1), ntt(b, 1);
    for (int i = 0; i < lim; ++i) a[i] = (long long) a[i] * b[i] % mod;
    ntt(a, 0);
    //while((int)a.size() && a.back() == 0) a.pop_back();
    return a;
}

template <const int32_t MOD>
struct modint {
    int32_t value;
    modint() = default;
    modint(int32_t value_) : value(value_) {}
    inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
    inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
    inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
    inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
    inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (modint<MOD> other) const { return value == other.value; }
    inline bool operator != (modint<MOD> other) const { return value != other.value; }
    inline bool operator < (modint<MOD> other) const { return value < other.value; }
    inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

struct Combi{
	int n; vector<mint> facts, finvs, invs;
	Combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
		facts[0] = finvs[0] = 1;
		invs[1] = 1;
	    for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
		for(int i = 1; i < n; i++){
			facts[i] = facts[i - 1] * i;
			finvs[i] = finvs[i - 1] * invs[i];
		}
	}
	inline mint fact(int n) { return facts[n]; }
	inline mint finv(int n) { return finvs[n]; }
	inline mint inv(int n) { return invs[n]; }
	inline mint ncr(int n, int k) { return n < k ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};
Combi C(N);

int a[N];
mint  f[N];
vector<int> c[N];
vector<int> yo(int l, int r) {
	if (l == r) return c[l];
	int mid = l + r >> 1;
	return multiply(yo(l, mid), yo(mid + 1, r));
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		a[k]++;
	}
	f[0] = 1;
	for (int i = 2; i < N; i += 2) {
		f[i] = C.fact(i) / C.fact(i / 2) / mint(2).pow(i / 2);
	}
	for (int i = 1; i < N; i++) {
		c[i] = vector<int> (a[i] + 1, 0);
		c[i][0] = 1;
		for (int k = 2; k <= a[i]; k += 2) {
			c[i][k] = (C.ncr(a[i], k) * f[k]).value;
		}
	}
	auto cnt = yo(1, 100000);
	cnt.resize(n + 1);
	mint ans = 0;
	for (int i = 0; i <= n; i += 2) {
		mint sgn = (i / 2) & 1 ? mod - 1 : 1;
		ans += sgn * f[n - i] * cnt[i];
	}
	cout << ans << '\n';
    return 0;
}
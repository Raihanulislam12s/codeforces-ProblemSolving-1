#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define dist(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
typedef long long ll;
const int mod=1e9+7;
const int mxn=1e6+9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k,ll mod) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}

typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.L);

template<class T> struct cplx {
  T x, y; cplx() {x = 0.0; y = 0.0;}
  cplx(T nx, T ny=0) {x = nx; y = ny;}
  cplx operator+(const cplx &c) const {return {x + c.x, y + c.y};}
  cplx operator-(const cplx &c) const {return {x - c.x, y - c.y};}
  cplx operator*(const cplx &c) const {return {x*c.x - y*c.y, x*c.y + y*c.x};}
  cplx& operator*=(const cplx &c) { return *this={x*c.x-y*c.y, x*c.y+y*c.x}; }
  inline T real() const { return x; }
  inline T imag() const { return y; }
  // Only supports right scalar multiplication like p*c
  template<class U> cplx operator*(const U &c) const {return {x*c,y*c};}
  template<class U> cplx operator/(const U &c) const {return {x/c,y/c};}
  template<class U> void operator/=(const U &c) {x /= c; y /= c;}};
#define polar(r,a)  (cplx<ld>){r*cos(a),r*sin(a)}

const int DIG = 9, FDIG = 4;
const int BASE = 1e9, FBASE = 1e4;
typedef cplx<ld> Cplx;

struct BigInt {
    int sgn;
    vector<int> a;
    BigInt() : sgn(1) {}
    BigInt(ll v) { *this = v; }
    BigInt& operator = (ll v) { sgn = 1; if (v < 0) sgn = -1, v = -v;
        a.clear(); for (; v > 0; v /= BASE) a.push_back(v % BASE);
        return *this; }
    BigInt(const BigInt& other) { sgn = other.sgn; a = other.a; }
    friend void swap(BigInt& a, BigInt& b) { swap(a.sgn, b.sgn);
        swap(a.a, b.a); }
    BigInt& operator = (BigInt other) { swap(*this, other); return *this; }
    BigInt(BigInt&& other) : BigInt() { swap(*this, other); }
    BigInt(const string& s) { read(s); }
    void read(const string& s) {
        sgn = 1; a.clear(); int k = 0;
        for (; k < s.size() && (s[k] == '-' || s[k] == '+'); k++)
            if (s[k] == '-') sgn = -sgn;
        for (int i = s.size()-1; i >= k; i -= DIG) {
            int x = 0;
            for (int j = max(k, i-DIG+1); j <= i; j++) x = x*10 + s[j] - '0';
            a.push_back(x); } trim(); }
    friend istream& operator>>(istream &in, BigInt &v) {
        string s; in >> s; v.read(s); return in; }
    friend ostream& operator<<(ostream &out, const BigInt &v) {
        if (v.sgn == -1 && !v.zero()) out << '-';
        out << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            out << setw(DIG) << setfill('0') << v.a[i];
        return out; }
    bool operator<(const BigInt &v) const { if (sgn != v.sgn) return sgn < v.sgn;
        if (a.size() != v.a.size()) return a.size() * sgn < v.a.size() * v.sgn;
        for (int i=(int)a.size()-1;i>=0;i--)
        if (a[i]!=v.a[i]) return a[i]*sgn < v.a[i]*sgn; return 0; }
    bool operator>(const BigInt &v) const { return v < *this; }
    bool operator<=(const BigInt &v) const { return !(v < *this); }
    bool operator>=(const BigInt &v) const { return !(*this < v); }
    bool operator==(const BigInt &v) const { return !(*this < v) && !(v < *this); }
    bool operator!=(const BigInt &v) const { return *this < v || v < *this; }
    friend int __cmp(const BigInt& x, const BigInt& y) {
        if (x.a.size() != y.a.size()) return x.a.size() < y.a.size() ? -1 : 1;
        for (int i = (int) x.a.size() - 1; i >= 0; --i) if (x.a[i] != y.a[i])
        return x.a[i] < y.a[i] ? -1 : 1; return 0; }

    BigInt operator-() const { BigInt res = *this; if (zero()) return res;
        res.sgn = -sgn; return res; }

    void __add(const BigInt& v) { if (a.size() < v.a.size()) a.resize(v.a.size(), 0);
        for (int i = 0, carry = 0; i < max(a.size(), v.a.size()) || carry; ++i) {
            if (i == a.size()) a.push_back(0);
            a[i] += carry + (i < (int) v.a.size() ? v.a[i] : 0); carry = a[i] >= BASE;
            if (carry) a[i] -= BASE; } }

    void __sub(const BigInt& v) {
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
            a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = a[i] < 0; if (carry) a[i] += BASE; } this->trim(); }

    BigInt operator+=(const BigInt& v) { if (sgn == v.sgn) __add(v);
        else if (__cmp(*this, v) >= 0) __sub(v);
    else { BigInt vv = v; swap(*this, vv); __sub(vv); } return *this; }

    BigInt operator-=(const BigInt& v) { if (sgn == v.sgn) {
        if (__cmp(*this, v) >= 0) __sub(v);
        else { BigInt vv = v; swap(*this, vv); __sub(vv); sgn = -sgn; } }
    else __add(v); return *this; }

    template< typename L, typename R >
        typename enable_if<
            is_convertible<L, BigInt>::value &&
            is_convertible<R, BigInt>::value &&
            is_lvalue_reference<R&&>::value,
            BigInt>::type friend operator + (L&& l, R&& r) {
        BigInt result(forward<L>(l));
        result += r;
        return result;
    }
    template< typename L, typename R >
        typename enable_if<
            is_convertible<L, BigInt>::value &&
            is_convertible<R, BigInt>::value &&
            is_rvalue_reference<R&&>::value,
            BigInt>::type friend operator + (L&& l, R&& r) {
        BigInt result(move(r));
        result += l;
        return result;
    }
    template< typename L, typename R >
        typename enable_if<
            is_convertible<L, BigInt>::value &&
            is_convertible<R, BigInt>::value,
            BigInt>::type friend operator - (L&& l, R&& r) {
        BigInt result(forward<L>(l));
        result -= r;
        return result;
    }

    friend pair<BigInt, BigInt> divmod(const BigInt& a1, const BigInt& b1) {
        ll norm = BASE / (b1.a.back()+1); BigInt a = a1.abs()*norm, b = b1.abs()*norm, q = 0, r = 0;
        q.a.resize(a.a.size());
        for (int i = a.a.size()-1; i >= 0; i--) { r *= BASE; r += a.a[i];
            ll s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            ll s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            ll d = ((ll) BASE * s1 + s2) / b.a.back(); r -= b * d;
            while (r < 0) r += b, --d; q.a[i] = d; }
        q.sgn = a1.sgn * b1.sgn; r.sgn = a1.sgn; q.trim(); r.trim();
        auto res = make_pair(q, r / norm); if (res.second < 0) res.second += b1; return res; }
    BigInt operator/(const BigInt &v) const { return divmod(*this, v).first; }
    BigInt operator%(const BigInt &v) const { return divmod(*this, v).second; }
    void operator/=(int v) { if (llabs(v) >= BASE) { *this /= BigInt(v); return; }
        if (v < 0) sgn = -sgn, v = -v;
        for (int i = (int) a.size()-1, rem = 0; i >= 0; --i) {
            ll cur = a[i] + rem * (ll)BASE; a[i] = (int) (cur/v); rem = (int) (cur%v); } trim(); }
    BigInt operator/(int v) const { if (llabs(v) >= BASE) return *this / BigInt(v);
        BigInt res = *this; res /= v; return res; }
    void operator/=(const BigInt &v) { *this = *this / v; }
    ll operator%(ll v) const { int m = 0;
        for (int i = a.size() - 1; i >= 0; --i) m = (a[i] + m * (ll) BASE) % v;
        return m * sgn; }
    void operator*=(int v) {
        if (llabs(v) >= BASE) { *this *= BigInt(v); return; }
        if (v < 0) sgn = -sgn, v = -v;
        for (int i = 0, carry = 0; i < a.size() || carry; ++i) {
            if (i == a.size()) a.push_back(0);
            ll cur = a[i] * (ll) v + carry;
            carry = (int) (cur/BASE); a[i] = (int) (cur%BASE); } trim(); }
    BigInt operator*(int v) const { if (llabs(v) >= BASE) return *this * BigInt(v);
        BigInt res = *this; res *= v; return res; }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<ll> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        ll cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back((ll)(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    void fft(vector<Cplx>& a, bool invert) const { int n = a.size();
        for (int i = 1, j = 0; i < n; ++i) { int bit = n/2;
            for (; j >= bit; bit /= 2) j -= bit; j += bit;
            if (i < j) swap(a[i], a[j]); }
        for (int len = 2; len <= n; len *= 2) {
            ld ang = 2 * PI / len * (invert ? -1 : 1);
            Cplx wlen = polar(1, ang);
            for (int i = 0; i < n; i += len) { Cplx w(1);
                for (int j = 0; j < len / 2; ++j) {
                    Cplx u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wlen; } } }
        if (invert) for (int i = 0; i < n; ++i) a[i] /= n; }
    void multiply_fft(const vector<int> &a, const vector<int> &b, vector<int> &res) const {
        vector<Cplx> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1; while (n < max(a.size(), b.size())) n *= 2; n *= 2; fa.resize(n); fb.resize(n);
        fft(fa, 0); fft(fb, 0); for (int i = 0; i < n; ++i) fa[i] *= fb[i]; fft(fa, 1);
        res.resize(n); ll carry = 0;
        for (int i=0; i<n; i++) { ll t = (ll)(fa[i].real()+0.5)+carry; carry = t/FBASE; res[i] = t%FBASE; } }
    static inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
      while ( a&msk ) { cnt++; a<<=1; }
      a &= msk-1; a |= msk;
      while ( cnt-- ) a >>= 1;
      return a; }
    static vector<Cplx> FFT(vector<Cplx> v, int dir=1) {
      Cplx wm,w,u,t; int n = v.size(); vector<Cplx> V(n);
      for (int k=0,a=0; k<n; ++k, a=rev_incr(a,n))
        V[a] = v[k] / ld(dir>0 ? 1 : n);
      for (int m=2; m<=n; m<<=1) {
        wm = polar( (ld)1, dir*2*PI/m );
        for (int k=0; k<n; k+=m) {
          w = 1;
          for (int j=0; j<m/2; ++j, w*=wm) {
            u = V[k + j];
            t = w * V[k + j + m/2];
            V[k + j] = u + t;
            V[k + j + m/2] = u - t;
          } } } return V; }
    static void convolution(const vector<int>& a, const vector<int>& b, vector<int>& c) {
      int sz = a.size()+b.size()-1;
      int n  = 1<<int(ceil(log2(sz)));
      vector<Cplx> av(n,0), bv(n,0), cv;
      for (int i=0; i<a.size(); i++) av[i] = a[i];
      for (int i=0; i<b.size(); i++) bv[i] = b[i];
      cv = FFT(bv); bv = FFT(av);
      for (int i=0; i<n; i++) av[i] = bv[i]*cv[i];
      cv = FFT(av, -1);
      c.resize(n); ll carry = 0;
      for (int i=0; i<n; i++) { ll t = ll(cv[i].real()+0.5)+carry; carry = t/FBASE; c[i] = t%FBASE; } }
    BigInt mul_simple(const BigInt &v) const { BigInt res; res.sgn = sgn * v.sgn;
        res.a.resize(a.size() + v.a.size());
        for (int i=0; i<a.size(); i++) if (a[i])
        for (int j=0, carry=0; j<v.a.size() || carry; j++) {
        ll cur = res.a[i + j] + (ll) a[i] * (j < v.a.size() ? v.a[j] : 0) + carry;
        carry = (int) (cur / BASE); res.a[i + j] = (int) (cur % BASE); } res.trim(); return res; }
    BigInt mul_fft(const BigInt& v) const { BigInt res;
        convolution(convert_base(a, DIG, FDIG), convert_base(v.a, DIG, FDIG), res.a);
        res.a = convert_base(res.a, FDIG, DIG); res.trim(); return res; }
    void operator*=(const BigInt &v) { *this = *this * v; }
    BigInt operator*(const BigInt &v) const {
        if (1LL*a.size() * v.a.size() <= 1000111) return mul_simple(v); return mul_fft(v); }

    BigInt abs() const { BigInt res = *this; res.sgn *= res.sgn; return res; }
    void trim() { while (!a.empty() && !a.back()) a.pop_back(); }
    bool zero() const { return a.empty() || (a.size() == 1 && !a[0]); }
    friend BigInt gcd(const BigInt &a, const BigInt &b) { return b.zero() ? a : gcd(b, a % b); }
};
BigInt getpow(BigInt a, ll k)
{
    BigInt ans=1;
    while(k>0){
        if(k&1) ans*=a;
        a*=a;
        k>>=1;
    }
    return ans;
}
ll phi(ll n)
{
    ll i,ans=n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            ans=ans/i*(i-1);
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
#define MOD(a,b)            ((a<b)?a:b+a%b)
int main()
{
    fast;
    ll i,j,m;
    //freopen("check.txt","r",stdin);
    string bb,nn;
    cin>>bb>>nn;
    BigInt b=BigInt(bb),n=BigInt(nn);
    ll c;
    cin>>c;
    ll mod=phi(c);
    BigInt p=(n-1)<mod?n-1:(n-1)%mod+mod;
    ll nw=0,k=1;
    while(p>0){
        nw=(p%10)*k+nw;
        p/=10;
        k*=10;
    }
    ll d=b%c;
    ll x=qpow(d,nw,c);
    ll y=(b-1+c)%c;
    cout<<(x*y%c==0?c:x*y%c)<<nl;
    return 0;
}


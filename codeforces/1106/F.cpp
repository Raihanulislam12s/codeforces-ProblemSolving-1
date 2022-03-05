#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
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
#define inf 1e18
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sz(v) (int)v.size()
#define pf printf
#define sf scanf
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=998244353-1;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


struct matrix
{
	int n;
	vector<vector<int> > t;

	matrix() { }
	matrix(int _n, int val) {n = _n; t.assign(n, vector<int>(n, val)); }
	matrix(int _n) {n = _n; t.assign(n, vector<int>(n, 0)); }
	matrix(vector<vi> v){n=v.size();t=v;}
	matrix unit(int _n)
	{
	    matrix ans=matrix(_n,0);
	    for(int i=0;i<_n;i++) ans.t[i][i]=1;
	    return ans;
	}
	///make sure to erase mod if not needed
	matrix operator * (matrix b)
	{
		matrix c = matrix(n, 0);
		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				for(int j = 0; j < n; j++)
					c.t[i][j] = (c.t[i][j] + 1LL*t[i][k] * b.t[k][j]%mod) % mod;
		return c;
	}
	matrix operator | (matrix b)
	{
		matrix c = matrix(n, -inf);
		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				for(int j = 0; j < n; j++)
					c.t[i][j] = max(c.t[i][j], t[i][k] + b.t[k][j]);
		return c;
	}
	matrix pow(ll k)
	{
        if(k==0) return unit(n);
        k--;
        matrix a=*this,ans=a;
        while(k){
            if(k&1) ans=ans*a;
            a=a*a;
            k>>=1;
        }
        return ans;
	}
	matrix pow_max(ll k)
	{
        if(k==0) return unit(n);
        k--;
        matrix a=*this,ans=a;
        while(k){
            if(k&1) ans=ans|a;
            a=a|a;
            k>>=1;
        }
        return ans;
	}
	matrix operator + (matrix a)
	{
        matrix ans=matrix(n,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            ans.t[i][j]=t[i][j]+a.t[i][j];
        return ans;
	}

	matrix operator - (matrix a)
	{
        matrix ans=matrix(n,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            ans.t[i][j]=t[i][j]-a.t[i][j];
        return ans;
	}
    bool operator == (const matrix& a)
	{
	    return t==a.t;
	}
    bool operator != (const matrix& a)
	{
	    return t!=a.t;
	}
	void print()
	{
	    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cout<<t[i][j]<<" \n"[j==n-1];
	}
};
int gcd (int a, int b) {
    return a ? gcd (b%a, a) : b;
}

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int get(int n,int k,int a){
    if (a == 0) {
        return 1;
    }

    int g = generator (n);

    int sq = (int) sqrt (n + .0) + 1;
    vector < pair<int,int> > dec (sq);
    for (int i=1; i<=sq; ++i)
        dec[i-1] = make_pair (powmod (g, int (i * sq * 1ll * k % (n - 1)), n), i);
    sort (dec.begin(), dec.end());
    int any_ans = -1;
    for (int i=0; i<sq; ++i) {
        int my = int (powmod (g, int (i * 1ll * k % (n - 1)), n) * 1ll * a % n);
        vector < pair<int,int> >::iterator it =
            lower_bound (dec.begin(), dec.end(), make_pair (my, 0));
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) {
        return -1;
    }

    int delta = (n-1) / gcd (k, n-1);
    for (int cur=any_ans%delta; cur<n-1; cur+=delta)
        return (powmod (g, cur, n));
}
int p[N];
int main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    cin>>k;
    for(i=0;i<k;i++) cin>>p[i];
    cin>>n>>m;
    matrix a(k);
    for(i=0;i<k;i++) a.t[0][i]=p[i];
    for(i=1;i<k;i++) a.t[i][i-1]=1;
    matrix ans=a.pow(n-k);
    int res=ans.t[0][0];
    int p=get(mod+1,res,m);
    cout<<p<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1


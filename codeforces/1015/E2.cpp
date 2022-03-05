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
#define PI (acos(-1.0))
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
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int mxn=1200;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
vector<pair<ll,pll>>v;
vs a;
ll le[mxn][mxn],ri[mxn][mxn],top[mxn][mxn],bot[mxn][mxn],row[mxn][mxn],col[mxn][mxn];
int main()
{
    fast;
    ll i,j,k,n,m,t;
    string s;
    cin>>n>>m;
    for(i=0;i<n;i++) cin>>s,a.eb(s);
    for(i=0;i<n;i++){
        le[i][0]=(a[i][0]=='*');
        for(j=1;j<m;j++){
            if(a[i][j]=='*') le[i][j]=le[i][j-1]+1;
        }
    }
    for(i=0;i<n;i++){
        ri[i][m-1]=(a[i][m-1]=='*');
        for(j=m-2;j>=0;j--){
            if(a[i][j]=='*') ri[i][j]=ri[i][j+1]+1;
        }
    }
    for(j=0;j<m;j++){
        top[0][j]=(a[0][j]=='*');
        for(i=1;i<n;i++){
            if(a[i][j]=='*') top[i][j]=top[i-1][j]+1;
        }
    }
    for(j=0;j<m;j++){
        bot[n-1][j]=(a[n-1][j]=='*');
        for(i=n-2;i>=0;i--){
            if(a[i][j]=='*') bot[i][j]=bot[i+1][j]+1;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='*'){
                ll mn=min({le[i][j],ri[i][j],top[i][j],bot[i][j]});
                mn--;
                if(mn<=0) continue;
                v.pb({i+1,{j+1,mn}});
                row[i][j-mn]++;
                row[i][j+mn+1]--;
                col[i-mn][j]++;
                col[i+mn+1][j]--;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<m;j++) row[i][j]+=row[i][j-1];
    }
    for(j=0;j<m;j++){
        for(i=1;i<n;i++) col[i][j]+=col[i-1][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='*'){
                if(row[i][j]==0&&col[i][j]==0) return cout<<-1<<nl,0;
            }
        }
    }
    cout<<v.size()<<nl;
    for(auto x:v) cout<<x.F<<' '<<x.S.F<<' '<<x.S.S<<nl;
    return 0;
}

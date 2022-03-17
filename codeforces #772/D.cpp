#include <bits/stdc++.h>

using namespace std;

#define ICO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define _ 0
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
#define endl '\n'
#define cpy(a, b) memcpy(a, b, sizeof(a))
#define int long long
//#define int __int128
#define lowbit(x) (x&(-x))
#define mod(x) ((x % mod) + mod) % mod
#define X(a) a.first
#define Y(a) a.second
#define time_start clock_t start_time = clock()
#define time_end clock_t end_time = clock()
#define the_time "The run time is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s"

//char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1<<23], *O=obuf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vet;
typedef vector<ll> vell;
typedef queue<int> quint;
typedef queue<ll> qull;
typedef map<int, int> mpit;
typedef map<pii, int> mppt;

const int inf_int = 0x7f7f7f7f;
const ll inf_ll = 0x7f7f7f7f7f7f7f7f;
const double inf_db = 1e18;
const int N = 2e5 + 10;
const int M = 2e6 + 7;
const int mod = 1e9 + 7;
int32_t t = 1;

inline int read()
{
    int x = 0, f = 1, ch = getchar(); while( !isdigit(ch) ){if(ch == '-') f = -1; ch = getchar();}
    while( isdigit(ch) ){x = (x << 1) + (x << 3) + ch - 48; ch = getchar();} return x * f;
}

inline void write(int n){ if (n < 0) { putchar('-'); n *= -1;} if (n > 9) { write(n / 10); } putchar(n % 10 + '0');}

int qmi(int a,int b,int c) {int res = 1;while(b) {if(b & 1)res = res * a % c;b >>= 1;a = a * a % c;} return res;}
int qmi(int a,int b) {int res = 1;while(b) {if(b & 1)res *= a;b >>= 1;a *= a;} return res;}

int a[N], aa[N], c[N];
int ok[100];

int32_t main()
{
    ICO;
    time_start;

//...........................................................................................

    aa[1] = 1;
    for(int i = 2; i <= 200000; ++i) aa[i] = (aa[i - 1] + aa[i - 2] + 1) % mod;
//    cin >> t;

    while(t--)
    {
        int n, p;
        cin >> n >> p;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int cnt = 0;
        c[1] = a[1];
        for(int i = 1; i <= n; ++i)
        {
            int b = a[i];
            bool book = 1;
            while(b >= c[1])
            {
                if(binary_search(c + 1, c + cnt + 1, b)) {book = 0; break;}
                if(b % 4 == 0) b >>= 2; else if(b & 1) b >>= 1; else break;
            }
//            cout << b << ' ' << book << endl;
            if(book)
            {
                c[++cnt] = a[i];
                int q = 0;
                while(a[i]) {a[i] /= 2; ++q;}
                ok[q]++;
            }

        }
        int res = 0;
        for(int i = 1; i <= 40; ++i)
            if(ok[i] && p + 1 - i > 0) res = (res + aa[p + 1 - i] * ok[i] % mod) % mod;

        cout << res << endl;

    }

//...........................................................................................
    time_end;
    cerr << the_time << endl;
    return ~~(0^_^0);
}


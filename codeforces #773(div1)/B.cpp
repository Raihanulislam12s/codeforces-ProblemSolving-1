#include<bits/stdc++.h>

#include <chrono>
#include <random>
#define lli long long int
using namespace std;
#define mod1 1000000007
#define mod 998244353
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 2000000000
#define common cout << "Case #" << w+1 << ": "
#define maxn 10000010
#define debug(x) cout << #x << ' ' <<  x << '\n'
#pragma GCC target("avx2")

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

template< typename T>
void PVecPrint(vector<T>&v, int len = -1)
{
    if (len == -1) {
        len = (int) v.size();
    }
    for(int i=0;i<len ;i++)
        cout << v[i].first << "," << v[i].second << ' ';
    cout << '\n';
}
template<class T>
void VecPrint(vector<T>&v, int len = -1)
{
    if (len == -1) {
        len = (int) v.size();
    }
    for(int i=0;i<len;i++)
        cout << v[i] << ' ';
    cout << '\n';
}
/*-------------------------------------------------------------------Code-----------------------------------------------------------------*/

vector<int> rev(vector<int> & v, int l, int r) {
    vector<int> ans;
    if (l > r) {
        return ans;
    }
    int len = r - l + 1;
    ans.resize(len);
    int id = r;
    for (int i = 0; i < len; i++) {
        ans[i] = v[id];
        --id;
    }
    return ans;
}

int findInd(vector<int> & v, int val) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == val) {
            return i;
        }
    }
    return -1;
}

int isOk (vector<int> & v) {
    int len = v.size();
    if (len % 2) {
        return 0;
    }
    int k = len / 2;
    for (int i = 0; i < len / 2; i++) {
        if (v[i] != v[i + k]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    fastio;
    int te;
    cin >> te;
    while (te--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m[v[i]] += 1;
        }
        int f = 1;
        for (auto & ent : m) {
            if (ent.second % 2) {
                f = 0;
            }
        }
        if (f) {
            int prev = 0;
            vector<int> ans;
            vector<pair<int, int> > q;
            while (!isOk(v)) {
                // VecPrint<int> (v);
                int id = findInd(v, v[0]);
                // cout << "id = " << id << '\n';
                int len = id + 1;
                for (int j = 1; j < id; j++) {
                    q.push_back({len + prev, v[j]});
                    ++len;
                }
                ans.push_back(id * 2);
                prev += id * 2;
                vector<int> t = rev(v, 1, id - 1);
                // VecPrint<int>(t);
                for (int i = id + 1; i < v.size(); i++) {
                    t.push_back(v[i]);
                }
                v = t;
                // VecPrint<int> (v);
                // break;
            }
            if (v.size())
                ans.push_back(v.size());
            cout << q.size() << '\n';
            for (auto & ent : q) {
                cout << ent.first << ' ' << ent.second << '\n';
            }
            cout << ans.size() << '\n';
            for (int & ent : ans) {
                cout << ent << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}

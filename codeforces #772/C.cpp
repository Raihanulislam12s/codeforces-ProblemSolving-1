#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstring>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
#define MOD 1000000009
#define NL printf("\n");    //Newline
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define FOR(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
typedef vector<ll> vl;

void printVec(vector<int> A){
    FOR(i,A.size()) printf("%d ",A[i]);
    NL;
}
void printVecLL(vector<ll> A){
    FOR(i,A.size()) printf("%lld ",A[i]);
    NL;
}


void solve(){
    int n;si(n);
    vi A(n);
    FOR(i,n){
        si(A[i]);
    }

    if(A[n-2] > A[n-1]){
        printf("-1\n");
        return;
    }

    if(A[n-1] >= 0){
        printf("%d\n",n-2);
        FOR(i,n-2){
            printf("%d %d %d\n",i+1,n-1,n);
        }
    }
    else{
        vi B = A;
        sort(all(B));
        if(A == B){
            printf("0\n");
        }
        else printf("-1\n" );
    }


}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    si(t);
    while(t--) solve();
    return 0;
}

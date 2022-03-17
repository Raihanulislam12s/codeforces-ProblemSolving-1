#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <queue>
#include <stack>
#include <map>
//----------define
#define el "\n"
#define debug(x) cout<<"#x = "<<x<<endl;
#define rep(i,n) for(int i=1; i<n; ++i)
#define erep(i,n) for(int i=1; i<=n; ++i)
#define rrep(i,n) for(int i=n; i>=1; i--)

#define pb push_back
#define pii pair<int, int>
#define pll pair<long,long>
#define mp make_pair

#define PI acos(-1)
using namespace std;
//----------typedef
typedef long long ll;

//----------const
const int mod = 1e9+7;
const int Maxn = 2*1e5+10;
const int INF = INT_MAX;

void solve(){
	string s1 = "12";
	string s2 = "21";
	int n;
	cin >> n;
	if(n==1 || n==2){
		printf("%d\n", n);
		return;
	}
	int t = n/3;
	int m = n%3;
	if(m==0){
		for(int i=0; i<t; i++) cout << s2;
	}
	if(m==1){
		for(int i=0; i<t; i++) cout << s1;
		printf("1");
	}
	if(m==2){
		for(int i=0; i<t; i++) cout << s2;
		printf("2");
	}
	printf("\n");

}

int main(void){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

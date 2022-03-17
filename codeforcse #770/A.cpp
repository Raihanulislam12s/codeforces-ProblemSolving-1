#include<bits/stdc++.h>
using namespace std;
int t;
int n,k;
string s,tt;
int main(){
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin >> n >> k;
		cin >> s;
		tt = s;
		reverse(tt.begin(),tt.end());
		if(tt!=s){
			if(k) cout << 2;
			else cout << 1;
		}else{
			cout << 1;
		}
		cout << "\n";
	}
	return 0;
}

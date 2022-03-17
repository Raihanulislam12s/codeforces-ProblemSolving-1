#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n%2==1&&k>1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        for (size_t i = 1; i <=n; i++)
        {
            int val=i;
            for (size_t j = 0; j < k; j++)
            {
                cout<<val<<" ";
                val+=n;
            }
            cout<<endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}

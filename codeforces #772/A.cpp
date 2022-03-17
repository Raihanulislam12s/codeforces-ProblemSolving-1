#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a,x=0;
        while(n--)
        {
            cin>>a;
            x=x|a;
        }
        cout<<x<<endl;
    }
}

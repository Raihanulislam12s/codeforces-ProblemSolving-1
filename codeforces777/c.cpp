
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<utility>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<iterator>
#include<iomanip>
#include<stack>
#include<cstdio>
#define ll long long
//#define int long long
#define endl "\n"
#define P pair<int,int>
#define f first
#define s second
using namespace std;
typedef unsigned long long ull;
const int maxn=110;
const int inf=0x3f3f3f3f;
const int mod=998244353;
int t;
int n,m,k;
char g[maxn][maxn];
bool pd(int xx,int yy)
{
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&g[xx][yy]=='1')
		return true;
	else
		return false;
}
void slove()
{
	if(g[1][1]!='0')
	{
		cout<<-1<<endl;
		return;
	}
	vector<pair<P,P> > a;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(g[i][j]=='1')
			{
				if(j!=1)
					a.push_back(make_pair(make_pair(i,j-1),make_pair(i,j)));
				else
					a.push_back(make_pair(make_pair(i-1,j),make_pair(i,j)));
			}
		}
	}
	cout<<a.size()<<endl;
	for(auto x:a)
		cout<<x.f.f<<" "<<x.f.s<<" "<<x.s.f<<" "<<x.s.s<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
    	for(int i=1;i<=n;i++)
    		cin>>g[i]+1;
    	slove();
	}
    return 0;
}



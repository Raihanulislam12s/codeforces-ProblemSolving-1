#include<bits/stdc++.h>
#define lll __int128
#define ll long long
#define ld long double
#define ul unsigned long long
using namespace std;
constexpr int N=2e5+5;
constexpr int M=4e5+5;
int n,m,a[N],b[N];
namespace sol2
{
	queue<int>q;
	struct edge{int z,t;}e[M];int h[N],ecn=0,d[N],tot;
	void add(int x,int y){e[++ecn]={y,h[x]},h[x]=ecn,d[y]++;}
	void work()
	{
		for(int i=1;i<=n;i++)
			if(!d[i])q.push(i),b[i]=++tot;
		while(q.size())
		{
			int nx=q.front();q.pop();
			for(int i=h[nx];i;i=e[i].t)
			{
				d[e[i].z]--;
				if(!d[e[i].z])q.push(e[i].z),b[e[i].z]=++tot;
			}
		}
		if(tot!=n)
		{
			printf("NO\n");
			return;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			if(a[i])printf("R %d\n",b[i]);
			else printf("L %d\n",b[i]);
		}
	}
}
namespace sol1
{
	struct edge{int z,t,w;}e[M];int h[N],ecn=0,v[N];
	void add(int x,int y,int z){e[++ecn]={y,h[x],z},h[x]=ecn;}
	void dfs(int x,int op)
	{
		if(v[x])return;
		a[x]=op;v[x]=1;
		for(int i=h[x];i;i=e[i].t)
			dfs(e[i].z,!op);
	}
	void work()
	{
		int x,y,z;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&z,&x,&y),
			add(x,y,z),add(y,x,z);
		for(int i=1;i<=n;i++)
			dfs(i,0);
		for(int i=1;i<=n;i++)
			for(int j=h[i];j;j=e[j].t)
			{
				if(a[i]==a[e[j].z])
				{
					printf("NO\n");
					return;
				}
				if(e[j].z<i)continue;
				if((!a[i]&&e[j].w==1)||(a[i]&&e[j].w==2))
					sol2::add(i,e[j].z);
				else sol2::add(e[j].z,i);
			}
		sol2::work();
	}
}
signed main()
{
	sol1::work();
	return 0;
}

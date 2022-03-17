#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[100010][10],w[100010],val[500010],sta[100010],f[1<<10];
map<int,int>mp;
mt19937 rnd(time(0));
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1,x;j<=m;j++)
		{
			scanf("%d",&x);
			if(mp.find(x)==mp.end())mp[x]=++cnt;
			a[i][j]=mp[x];
		}
		scanf("%d",&w[i]);
	}
	int t=100,ans=2e9+1;
	while(t--)
	{
		for(int i=1;i<=cnt;i++)val[i]=1<<(rnd()%10);
		memset(f,0x7f,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			sta[i]=0;
			for(int j=1;j<=m;j++)sta[i]|=val[a[i][j]];
			f[sta[i]]=min(f[sta[i]],w[i]);
		}
		for(int i=0;i<10;i++)
			for(int msk=0;msk<(1<<10);msk++)f[msk|(1<<i)]=min(f[msk|(1<<i)],f[msk]);
		for(int i=1;i<=n;i++)
		{
			int v=f[((1<<10)-1)^sta[i]];
			if(v!=0x7f7f7f7f)ans=min(ans,w[i]+v);
		}
	}
	if(ans<=2e9)printf("%d",ans);
	else puts("-1");
	return 0;
}

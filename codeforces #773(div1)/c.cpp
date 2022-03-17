#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=2e5+10;
int n,T,f[N],g[N];
int getf(int x){
	if(x==f[x])return x;
	f[x]=getf(f[x]);
	g[f[x]]=min(g[f[x]],g[x]);
	return f[x];
}
int main(){
	// freopen("data.in","r",stdin);
	scanf("%d%d",&n,&T);
	fo(i,1,n+2)f[i]=i,g[i]=n+2;
	while(T--){
		int opt;
		scanf("%d",&opt);
		if(!opt){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(!x){
				for(int p=getf(l);p<=r;p=getf(p)){
					int y=getf(p+1);
					f[p]=y;
					g[y]=min(g[y],g[p]);
				}
			}else{
				int X=getf(l);
				g[X]=min(g[X],r);
			}
		}else{
			int x;
			scanf("%d",&x);
			if(f[x]>x)printf("NO\n");
			else{
				int l=g[getf(x)],r=getf(x+1);
				if(l<r)printf("YES\n");
				else printf("N/A\n");
			}
		}
	}

	return 0;
}

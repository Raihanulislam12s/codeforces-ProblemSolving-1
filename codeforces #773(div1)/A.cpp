#include<bits/stdc++.h>
#define R register
#define LL long long
using namespace std;
char buf[1<<21],*P1=buf,*P2=buf;
#define getchar() (P1==P2&&(P2=(P1=buf)+fread(buf,1,1<<21,stdin),P1==P2)?EOF:*P1++)
inline int read(){
	int x=0,d=1; char y=getchar();
	for(;y<'0'||y>'9';y=getchar())if(y=='-')d=-1;
	for(;y>='0'&&y<='9';y=getchar())x=(x<<3)+(x<<1)+(y^'0');
	return x*d;
}
const int N=5e5+10;
struct node{int a,b;}e[N];
int T,n,x,cnt[N];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	T=read();
	while(T--){
		n=read(); x=read();
		for(R int i=1,z;i<=n;i++){
			z=read(); e[i].b=0;
			while(z%x==0)z/=x,++e[i].b;
			e[i].a=z;
		}
		sort(e+1,e+n+1,[](node u,node v){return u.a<v.a||(u.a==v.a&&u.b<v.b);});
		int ans=0;
		for(R int i=1;i<=n;i++){
			int j=i; while(j<n&&e[i].a==e[j+1].a)++j;
			for(R int k=i;k<=j;k++)cnt[e[k].b]+=1;
			for(R int k=i;k<=j;k++){
				int w=e[k].b;
				if(cnt[w]&&cnt[w+1])--cnt[w],--cnt[w+1];
				else if(cnt[w])--cnt[w],++ans;
			}
			for(R int k=i;k<=j;k++)cnt[e[k].b]=0;
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}

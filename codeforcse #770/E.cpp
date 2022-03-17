#include<cstdio>
#include<vector>
#include<unordered_map>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define KFOR(i,a,b) for(int i=(a),HOHOlim=(b);i<=HOHOlim;++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define go(p,u) for(int p=head[u];p;p=edge[p].nxt)
using namespace std;
typedef long long LL;
const int NN=4e5+5;
int M;
int tot,val[NN];
struct E{
	int v,nxt;
	bool tag;
	E():v(0),nxt(0),tag(0){}
	E(int _v,int _nxt):v(_v),nxt(_nxt),tag(0){}
}edge[NN*2];
int head[NN],tote=1;
void AddE(int u,int v){
	edge[++tote]=E(v,head[u]);
	head[u]=tote;
}
int deg[NN];
unordered_map<int,int> side[NN],mp;
bool vis[NN];
void dfs(int u){
	vis[u]=1;
	for(int &p=head[u];p;p=edge[p].nxt){
		if(!edge[p].tag){
			edge[p].tag=1;
			edge[p^1].tag=1;
			if(u<=M)++side[u][edge[p].v];
			dfs(edge[p].v);
		}
	}
	// printf("%d ",u);
}
vector<int> A[NN];
int cnt[NN];
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	scanf("%d",&M);
	FOR(i,1,M){
		int t;scanf("%d",&t);
		if(t&1){
			printf("NO\n");
			return 0;
		}
		A[i].resize(t);
		FOR(j,0,t-1){
			scanf("%d",&A[i][j]);
			int id=0;
			if(mp.find(A[i][j])==mp.end()){
				mp[A[i][j]]=++tot;
				++cnt[tot];
				val[tot]=A[i][j];
				id=M+tot;
			}else{
				id=M+mp[A[i][j]];
				++cnt[mp[A[i][j]]];
			}
			AddE(i,id);
			AddE(id,i);
		}
	}
	FOR(i,1,tot)if(cnt[i]&1){printf("NO\n");return 0;}
	FOR(i,1,tot)if(!vis[i]){dfs(i);}
	printf("YES\n");
	FOR(i,1,M){
		KFOR(j,0,A[i].size()-1){
			if(side[i][M+mp[A[i][j]]]){
				printf("L");
				--side[i][M+mp[A[i][j]]];
			}else printf("R");
		}
		printf("\n");
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}

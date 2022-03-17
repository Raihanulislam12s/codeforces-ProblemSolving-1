#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e4+1;
inline int query(int i,int j,int k){
	printf("? %d %d %d\n",i,j,k);
	fflush(stdout);
	int num;
	scanf("%d",&num);
	return num;
}
inline void answer(int a,int b){
	printf("! %d %d\n",a,b);
	fflush(stdout);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		int i=1,j=2,w=3;
		int l=query(i,j,w);
		for (int k=4;k<=n;k++){
			int d1=query(i,j,k);
			int d2=query(j,w,k);
			if(l>=d1&&l>=d2)
				continue;
			else
				if(d1>=l&&d1>=d2)
					w=k,l=d1;
			else
				if(d2>=l&&d2>=d1)
					i=k,l=d2;
		}
		for (int k=1;k<=n;k++)
			if(k!=i&&k!=j&&k!=w){
				int ij=query(i,j,k);
				int iw=query(i,w,k);
				if (ij==l)
					answer(i,j);
				else
					if (iw==l)
						answer(i,w);
				else
					answer(j,w);
				break;
			}
	}
}

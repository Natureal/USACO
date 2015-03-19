/*
ID:naturec1
PROG: fence6
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 210;

int N;
int s[MAXN],L[MAXN];
int g[MAXN][MAXN][2];

int Dijstra(int st){
	int vis[MAXN],dis[MAXN];
	fill(dis + 1,dis + N + 1,INF);
	REP(i,N) if(g[st][i][0]) dis[i] = L[i];
	MEM(vis,0);
	REP(i,N - 1){
		int tmin = INF,p;
		REP(j,N) if(!vis[j] && dis[j] < tmin) tmin = dis[p = j];
		if(tmin >= INF) return INF;
		vis[p] = 1;
		REP(j,N) if(!vis[j] && g[p][j][0]){
			if(j == st) continue;
			if(dis[j] > dis[p] + L[j])
				dis[j] = dis[p] + L[j];
		}
		REP(j,N) if(!vis[j] && g[p][j][1]){
			if(j == st) continue;
			if(dis[j] > dis[p] + L[j])
				dis[j] = dis[p] + L[j];
		}
	}
	int res = INF;
	REP(i,N) if(g[st][i][1]) res = min(res,dis[i]);
	return res;
}

int main(){
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	int n1,n2,a;
	scanf("%d",&N);
	REP(i,N){
		scanf("%d%d%d%d",&s[i],&a,&n1,&n2);
		L[s[i]] = a;
		REP(j,n1){
			scanf("%d",&a);
			g[s[i]][a][0] = 1;
		}
		REP(j,n2){
			scanf("%d",&a);
			g[s[i]][a][1] = 1;
		}
	}
	int ans = INF;
	REP(i,N){
		ans = min(ans,L[i] + Dijstra(i));
	}
	printf("%d\n",ans);
	return 0;
}
	

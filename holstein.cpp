/*
ID:naturec1
PROG: holstein
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

int V,G,req[30];
int g[30][30];
int total;
int cur[30],vis[30];
int flag;

void Dfs(int p,int num){
	if(p > G && num < total) return;
	if(num >= total){
		bool tag = true;
		REP(i,V) if(cur[i] < req[i]){
			tag = false;
			break;
		}
		flag = tag;
		return;
	}
	REP(i,V) cur[i] += g[p][i];
	vis[p] = 1;
	Dfs(p + 1,num + 1);
	if(flag) return;
	REP(i,V) cur[i] -= g[p][i];
	vis[p] = 0;
	Dfs(p + 1,num);
}

int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&V);
	REP(i,V) scanf("%d",req + i);
	scanf("%d",&G);
	REP(i,G) REP(j,V) scanf("%d",&g[i][j]);
	for(int i = 1; i <= G; ++i){
		total = i;
		flag = false;
		Dfs(1,0);
		if(flag){
			printf("%d",i);
			REP(j,G) if(vis[j]) printf(" %d",j);
			puts("");
			break;
		}
	}
	return 0;
}



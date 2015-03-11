/*
ID:naturec1
PROG: wormhole
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

int N,ans;
int par[15],vis[15],rig[15];
int h[15][2];

bool Check(){
	int used[15];
	REP(i,N) if(rig[i]){
		MEM(used,0);
		used[i] = 1;
		int pos = i;
		while(rig[pos]){
			pos = par[rig[pos]];
			if(used[pos]) return true;
		}
	}
	return false;
}

void Dfs(int p){
	if(p > N){
		if(Check()) ++ans;
		return;
	}
	if(vis[p]){
		Dfs(p + 1);
		return;
	}
	REP(i,N) if(!vis[i] && i != p){
		par[p] = i;
		par[i] = p;
		vis[p] = vis[i] = 1;
		Dfs(p + 1);
		vis[p] = vis[i] = 0;
    }
}

int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	scanf("%d",&N);
	REP(i,N) scanf("%d%d",&h[i][0],&h[i][1]);
	REP(i,N){
		int id = 0;
		REP(j,N) if(h[i][0] < h[j][0] && h[i][1] == h[j][1]){
			if(id == 0) id = j;
			else if(h[j][0] < h[id][0]) id = j;
		}
		rig[i] = id;
	}
	Dfs(1);
	printf("%d\n",ans);
	return 0;
}


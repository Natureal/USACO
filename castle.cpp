/*
ID:naturec1
PROG: castle
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

int m,n,tot;
int g[55][55];
int id[55][55];
int grp[55][55];
int cnt[55 * 55];
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

void Dfs(int x,int y){
	cnt[tot]++;
	grp[x][y] = tot;
	for(int i = 0; i < 4; ++i){
		if(g[x][y] & (1 << i)) continue;
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(grp[tx][ty] == 0) Dfs(tx,ty);
	}
}		

int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	int tmax = 0;
	scanf("%d%d",&m,&n);
	REP(i,n) REP(j,m) scanf("%d",&g[i][j]),id[i][j] = (i - 1) * m + j;
	REP(i,n) REP(j,m) if(!grp[i][j]){
		++tot;
		Dfs(i,j);
		tmax = max(tmax,cnt[tot]);
	}
	printf("%d\n",tot);
	printf("%d\n",tmax);
	int ans = 0,posx,posy;
	char c;
	for(int j = 1; j <= m; ++j){
		for(int i = m; i >= 2; --i) if(g[i][j] & 2){
			int tmp = cnt[grp[i][j]];
			if(grp[i][j] != grp[i - 1][j]) tmp += cnt[grp[i - 1][j]];
			if(tmp > ans){
				ans = tmp;
				posx = i;
				posy = j;
				c = 'N';
			}
		}
		for(int i = m; i >= 1; --i) if(g[i][j] & 4){
			int tmp = cnt[grp[i][j]];
			if(grp[i][j] != grp[i][j + 1]) tmp += cnt[grp[i][j + 1]];
			if(tmp > ans){
				ans = tmp;
				posx = i;
				posy = j;
				c = 'E';
			}
		}
	}
	printf("%d\n",ans);
	printf("%d %d %c\n",posx,posy,c);
	return 0;
}


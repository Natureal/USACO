/*
ID:naturec1
PROG: snail
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int n,m;
int g[130][130];
bool vis[130][130];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int Dfs(int x,int y,int pre){
	if(vis[x][y]) return 0;
	vis[x][y] = 1;
	int tx = x + dir[pre][0];
	int ty = y + dir[pre][1];
	int res = 0;
	if(tx < 1 || tx > n || ty < 1 || ty > n || g[tx][ty]){
		REP(i,4){
			tx = x + dir[i][0];
			ty = y + dir[i][1];
			if(tx < 1 || tx > n || ty < 1 || ty > n || vis[tx][ty] || g[tx][ty])
				continue;
			int cur = Dfs(tx,ty,i);
			if(cur > 0) res = max(res,cur);
		}
	}
	else res = Dfs(tx,ty,pre);
	vis[x][y] = 0;
	return res + 1;
}

int main(){
	freopen("snail.in","r",stdin);
	freopen("snail.out","w",stdout);
	char s[10];
	scanf("%d%d",&n,&m);
	REP(i,m){
		scanf("%s",s);
		int x = s[0] - 'A' + 1;
		int y = 0;
		int len = strlen(s);
		for(int j = 1; j < len; ++j) y = y * 10 + s[j] - '0';
		g[y][x] = 1;
	}
	int ans = 0;
	printf("%d\n",max(Dfs(1,1,1),Dfs(1,1,3)));
	return 0;
}


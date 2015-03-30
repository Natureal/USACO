/*
ID:naturec1
PROG: starry
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

int W,H,clu_cnt,stx,sty;
int id[110][110];
char g[110][110];
int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

struct Cluster{
	bool mp[110][110];
	int num;
}clu[510];

void Dfs(int x,int y){
	clu[clu_cnt].mp[x][y] = 1;
	clu[clu_cnt].num++;
	id[x][y] = clu_cnt;
	REP(i,8){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx < 0 || tx >= H || ty < 0 || ty >= W 
				|| g[tx][ty] == '0' || id[tx][ty] != -1) continue;
		Dfs(tx,ty);
	}
}

void Move(bool graph[110][110]){
	int minx = INF,miny = INF;
	bool tmp[110][110] = {0};
	REP(i,H) REP(j,W) if(graph[i][j]){
		minx = min(minx,i);
		miny = min(miny,j);
	}
	REP(i,H) REP(j,W) if(graph[i][j]) tmp[i - minx][j - miny] = 1;
	memcpy(graph,tmp,sizeof(tmp));
}

bool Judge(bool g1[110][110],bool g2[110][110]){
	REP(i,H) REP(j,W) if(g1[i][j] ^ g2[i][j]) return false;
	return true;
}

bool Check(int a,int b){
	if(clu[a].num != clu[b].num) return false;

	bool tmp[110][110];
	if(Judge(clu[a].mp,clu[b].mp)) return true;
	
	//CW 90
	MEM(tmp,0);
	REP(i,H) REP(j,W) if(clu[a].mp[i][j]) tmp[j][W - i - 1] = 1;
	Move(tmp);
	if(Judge(tmp,clu[b].mp)) return true;
	//CW 180
	MEM(tmp,0);
	REP(i,H) REP(j,W) if(clu[a].mp[i][j]) tmp[H - i - 1][W - j - 1] = 1;
	Move(tmp);
	if(Judge(tmp,clu[b].mp)) return true;
	//CW 270
	MEM(tmp,0);
	REP(i,H) REP(j,W) if(clu[a].mp[i][j]) tmp[H - j - 1][i] = 1;
	Move(tmp);
	if(Judge(tmp,clu[b].mp)) return true;
	//overturn --------------------------------------
	REP(i,H) REP(j,W / 2) if(clu[a].mp[i][j])
		swap(clu[a].mp[i][j],clu[a].mp[i][W - j - 1]);
	Move(clu[a].mp);
	if(Judge(clu[a].mp,clu[b].mp)) return true;
	//CW 90
	MEM(tmp,0);
	REP(i,H) REP(j,W) if(clu[a].mp[i][j]) tmp[j][W - i - 1] = 1;
	Move(tmp);
	if(Judge(tmp,clu[b].mp)) return true;
	//CW 180
	MEM(tmp,0);
	REP(i,H) REP(j,W) if(clu[a].mp[i][j]) tmp[H - i - 1][W - j - 1] = 1;
	Move(tmp);
	if(Judge(tmp,clu[b].mp)) return true;
	//CW 270
	MEM(tmp,0);
	REP(i,H) REP(j,W) if(clu[a].mp[i][j]) tmp[H - j - 1][i] = 1;
	Move(tmp);
	if(Judge(tmp,clu[b].mp)) return true;
	
	return false;
}

int main(){
	freopen("starry.in","r",stdin);
	freopen("starry.out","w",stdout);
	MEM(id,-1);
	scanf("%d%d",&W,&H);
	REP(i,H) scanf("%s",g[i]);
	REP(i,H) REP(j,W) if(g[i][j] == '1'){
		if(id[i][j] != -1) continue;
		stx = i,sty = j;
		Dfs(i,j);
		clu_cnt++;
	}
	REP(i,clu_cnt) Move(clu[i].mp);
	int tot = 0,tag[510] = {0};
	REP(i,clu_cnt){
		if(tag[i]) continue;
		tag[i] = ++tot;
		FOR(j,i + 1,clu_cnt - 1) if(Check(i,j)){
			tag[j] = tag[i];
		}
	}
	REP(i,H){
		REP(j,W){
			if(g[i][j] == '0') printf("0");
			else printf("%c",'a' + tag[id[i][j]] - 1);
		}
		puts("");
	}
	return 0;
}


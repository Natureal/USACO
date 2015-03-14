/*
ID:naturec1
PROG: camelot
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
#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int R,C;
int dis[1010][35][35];
pii kg,kn[1010];
int dir[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int near[25][2] = {{0,0},{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1},
	{-2,-2},{-2,-1},{-2,0},{-2,1},{-2,2},{-1,-2},{-1,2},
	{0,-2},{0,2},{1,-2},{1,2},{2,-2},{2,-1},{2,0},{2,1},{2,2}};
int cnt,kcnt;

struct node{
	int x,y,step;
	node(int tx = 0,int ty = 0,int tstep = 0) :
		x(tx),y(ty),step(tstep) {}
};

void Bfs(int id){
	int x = kn[id].X;
	int y = kn[id].Y;
	queue<node> Q;
	REP(i,R) REP(j,C) dis[id][i][j] = -1;
	while(!Q.empty()) Q.pop();
	Q.push(node(x,y,0));
	dis[id][x][y] = 0;
	while(!Q.empty()){
		node cur = Q.front(); Q.pop();
		for(int i = 0; i < 8; ++i){
			int tx = cur.x + dir[i][0];
			int ty = cur.y + dir[i][1];
			if(tx < 1 || tx > R || ty < 1 || ty > C || ~dis[id][tx][ty]) continue;
			dis[id][tx][ty] = cur.step + 1;
			Q.push(node(tx,ty,cur.step + 1));
		}
	}
}

int Solve(int x,int y){
	int sum = 0,res;
	REP(i,kcnt){
		if(dis[i][x][y] == -1) return INF;
		sum += dis[i][x][y];
	}
	res = sum + abs(kg.X - x) + abs(kg.Y - y);
	REP(k,kcnt){ //which knight catches king
		for(int i = kcnt + 1; i <= cnt; ++i){
			int tx = kn[i].X;
			int ty = kn[i].Y;
			if(dis[k][tx][ty] == -1 || dis[i][x][y] == -1) continue;
			int add;
			if(kg.X == tx && kg.Y == ty) add = 0;
			else if(abs(kg.X - tx) > 1 || abs(kg.Y - ty) > 1) add = 2;
			else add = 1;
			res = min(res,sum - dis[k][x][y] + dis[k][tx][ty] + dis[i][x][y]
					+ add);
		}
	}
	return res;
}

int main(){
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	char s[5];
	int a;
	scanf("%d%d",&R,&C);
	scanf("%s%d",s,&a);
	kg = MP(a,s[0] - 'A' + 1);
	while(scanf("%s%d",s,&a) != EOF){
		++cnt;
		kn[cnt] = MP(a,s[0] - 'A' + 1);
	}
	kcnt = cnt; //kcnt : the number of knight
	for(int i = 0; i < 25; ++i){
		int tx = kg.X + near[i][0];
		int ty = kg.Y + near[i][1];
		if(tx < 1 || tx > R || ty < 1 || ty > C) continue;
		++cnt;
		kn[cnt] = MP(tx,ty);
	}
	REP(i,cnt) Bfs(i);
	int ans = INF,tem;
	REP(i,R) REP(j,C)	ans = min(ans,Solve(i,j));
	printf("%d\n",ans);
	return 0;
}


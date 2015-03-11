/*
ID:naturec1
PROG: maze1
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

int W,H,X[2],Y[2];
char g[205][205],s[205];
int vis[205][205],MD[205][205];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int Dir[4][2] = {{-2,0},{0,2},{2,0},{0,-2}};

struct nd{
	int x,y,step;
	nd(int tx = 0,int ty = 0,int tstep = 0) : x(tx),y(ty),step(tstep) {}
};

queue<nd> q;

void Bfs(int id){
	while(!q.empty()) q.pop();
	q.push(nd(X[id],Y[id],1));
	MEM(vis,0);
	vis[X[id]][Y[id]] = 1;
	while(!q.empty()){
		nd cur = q.front(); q.pop();
		MD[cur.x][cur.y] = min(MD[cur.x][cur.y],cur.step);
		for(int i = 0; i < 4; ++i){
			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];
			if(g[nx][ny] != ' ') continue;
			int Nx = cur.x + Dir[i][0];
			int Ny = cur.y + Dir[i][1];
			if(Nx<1 || Nx>2*H+1 || Ny<1 || Ny>2*W+1 || vis[Nx][Ny]) continue;
			vis[Nx][Ny] = 1;
			q.push(nd(Nx,Ny,cur.step + 1));
		}
	}
}

int main(){
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	scanf("%d%d",&W,&H);
	getchar();
	REP(i,2 * H + 1){
		gets(s);
		REP(j,2 * W + 1) g[i][j] = s[j - 1];
	}
	int cnt = 0;
	for(int i = 2; i < 2 * W + 1; i += 2){
		if(g[1][i] == ' '){
			X[cnt] = 2;
			Y[cnt] = i;
			cnt++;
		}
		if(g[2 * H + 1][i] == ' '){
			X[cnt] = 2 * H;
			Y[cnt] = i;
			cnt++;
		}
	}
	for(int i = 2; i < 2 * H + 1; i += 2){
		if(g[i][1] == ' '){
			X[cnt] = i;
			Y[cnt] = 2;
			cnt++;
		}
		if(g[i][2 * W + 1] == ' '){
			X[cnt] = i;
			Y[cnt] = 2 * W;
			cnt++;
		}
	}
	MEM(MD,0x3f);
	REP(i,2) Bfs(i - 1);
	int ans = 0;
	for(int i = 2; i < 2 * H + 1; i += 2)
		for(int j = 2; j < 2 * W + 1; j += 2)
			ans = max(ans,MD[i][j]);
	printf("%d\n",ans);
	return 0;
}



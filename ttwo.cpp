/*
ID:naturec1
PROG: ttwo
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

char g[15][15];
int fx,fy,fd,cx,cy,cd;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int main(){
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	REP(i,10) scanf("%s",g[i] + 1);
	REP(i,10) REP(j,10){
		if(g[i][j] == 'F') fx = i,fy = j;
		else if(g[i][j] == 'C') cx = i,cy = j;
	}
	int cnt = 0;
	fd = cd = 0;
	while((++cnt) < 10000){
		int n_fx = fx + dir[fd][0];
		int n_fy = fy + dir[fd][1];
		if(n_fx < 1 || n_fx > 10 || n_fy < 1 || n_fy > 10 || g[n_fx][n_fy] == '*')
			fd = (fd + 1) % 4;
		else fx = n_fx , fy = n_fy;
		int n_cx = cx + dir[cd][0];
		int n_cy = cy + dir[cd][1];
		if(n_cx < 1 || n_cx > 10 || n_cy < 1 || n_cy > 10 || g[n_cx][n_cy] == '*')
			cd = (cd + 1) % 4;
		else cx = n_cx , cy = n_cy;
		if(fx == cx && fy == cy) break;
	}
	printf("%d\n",cnt >= 10000 ? 0 : cnt);
	return 0;
}


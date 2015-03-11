/*
ID:naturec1
PROG: milk3
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

int A,B,C;
int vis[21][21][21];
int exi[21];

void Dfs(int a,int b,int c){
	if(vis[a][b][c]) return;
	if(a == 0) exi[c] = 1;
	vis[a][b][c] = 1;
	int tmin;
	tmin = min(a,B - b);	Dfs(a - tmin,b + tmin,c); //a -> b
	tmin = min(b,A - a);	Dfs(a + tmin,b - tmin,c); //b -> a
	tmin = min(a,C - c);	Dfs(a - tmin,b,c + tmin); //a -> c
	tmin = min(c,A - a);	Dfs(a + tmin,b,c - tmin); //c -> a
	tmin = min(b,C - c);	Dfs(a,b - tmin,c + tmin); //b -> c
	tmin = min(c,B - b);	Dfs(a,b + tmin,c - tmin); //c -> b
}

int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	Dfs(0,0,C);
	int head = 1;
	for(int i = 0; i <= C; ++i) if(exi[i]){
		if(head) printf("%d",i);
		else printf(" %d",i);
		head = 0;
	}
	puts("");
	return 0;
}

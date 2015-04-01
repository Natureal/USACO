/*
ID:naturec1
PROG: schlnet
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
const int MAXN = 110;

int N,tot,scnt;
int first[MAXN],ecnt;
int dfn[MAXN],low[MAXN],sc[MAXN];
int din[MAXN],dout[MAXN];
stack<int> stk;

struct edge{
	int v,next;
}e[MAXN * MAXN];

void Init(){
	MEM(first,-1);
	ecnt = 0;
	tot = 0;
	scnt = 0;
}

void Add_edge(int u,int v){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	first[u] = ecnt;
}

void Dfs(int p){
	dfn[p] = low[p] = ++tot;
	stk.push(p);
	for(int i = first[p]; ~i; i = e[i].next){
		int v = e[i].v;
		if(!dfn[v]){
			Dfs(v);
			low[p] = min(low[p],low[v]);
		}
		else if(!sc[v]){
			low[p] = min(low[p],dfn[v]);
		}
	}
	if(dfn[p] == low[p]){
		scnt++;
		for(;;){
			int x = stk.top(); stk.pop();
			sc[x] = scnt;
			if(x == p) break;
		}
	}
}

void Tarjan(){
	MEM(low,0);
	MEM(dfn,0);
	MEM(sc,0);
	while(!stk.empty()) stk.pop();
	FOR(i,1,N){
		if(!dfn[i]) Dfs(i);
	}
}

int main(){
	freopen("schlnet.in","r",stdin);
	freopen("schlnet.out","w",stdout);
	int a;
	Init();
	scanf("%d",&N);
	FOR(i,1,N){
		while(scanf("%d",&a) != EOF && a){
			Add_edge(i,a);
		}
	}
	Tarjan();
	FOR(i,1,N){
		for(int j = first[i]; ~j; j = e[j].next){
			int v = e[j].v;
			if(sc[i] != sc[v]){
				dout[sc[i]]++;
				din[sc[v]]++;
			}
		}
	}
	int cnt1 = 0,cnt2 = 0;
	FOR(i,1,scnt) if(din[i] == 0) cnt1++;
	FOR(i,1,scnt) if(dout[i] == 0) cnt2++;
	int ans1 = cnt1 == 0 ? 1 : cnt1;
	int ans2 = scnt == 1 ? 0 : max(cnt1,cnt2);
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}


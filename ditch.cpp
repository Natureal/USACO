/*
ID:naturec1
PROG: ditch
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
const int MAXN = 410;

int N,M;
struct edge{
	int v,next,cp;
};

struct Max_flow{
	int first[MAXN],lev[MAXN],ecnt,st,ed;
	edge e[MAXN * 4];
	void init(){
		MEM(first,-1);
		ecnt = 0;
	}
	void add_edge(int u,int v,int c){
		e[ecnt].next = first[u];
		e[ecnt].v = v;
		e[ecnt].cp = c;
		first[u] = ecnt++;
		
		e[ecnt].next = first[v];
		e[ecnt].v = u;
		e[ecnt].cp = 0;
		first[v] = ecnt++;
	}
	int dfs(int p,int minf){
		if(p == ed) return minf;
		for(int i = first[p]; ~i; i = e[i].next){
			int v = e[i].v;
			if(lev[v] > lev[p] && e[i].cp > 0){
				int d = dfs(v,min(e[i].cp,minf));
				if(d > 0){
					e[i].cp -= d;
					e[i ^ 1].cp += d;
					return d;
				}
			}
		}
		return 0;
	}
	bool bfs(){
		queue<int> Q;
		Q.push(st);
		MEM(lev,-1);
		lev[st] = 0;
		while(!Q.empty()){
			int cur = Q.front(); Q.pop();
			for(int i = first[cur]; ~i; i = e[i].next){
				int v = e[i].v;
				if(lev[v] < 0 && e[i].cp > 0){
					lev[v] = lev[cur] + 1;
					Q.push(v);
				}
			}
		}
		return lev[ed] != -1; //仍有增广流可到ed
	}
	int dinic(){
		int max_flow = 0,cur;
		while(bfs()){ //建立分层图
			while((cur = dfs(st,INF)) > 0)
				max_flow += cur;
		}
		return max_flow;
	}
}MF;

int main(){
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	int a,b,c;
	scanf("%d%d",&N,&M);
	MF.init();
	MF.st = 1;
	MF.ed = M;
	REP(i,N){
		scanf("%d%d%d",&a,&b,&c);
		MF.add_edge(a,b,c);
	}
	printf("%d\n",MF.dinic());
	return 0;
}


/*
ID:naturec1
PROG: milk6
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
const int MAXN = 50;
const int MAXM = 1010;

int N,M,S[MAXN];
struct edge{
	int u,v,next,id;
	ll cp;
};

struct Max_flow{
	int first[MAXN],ecnt;
	int st,ed,lev[MAXN];
	edge e[MAXM * 8];
	void init(int tst,int ted){
		MEM(first,-1);
		ecnt = 0;
		st = tst;
		ed = ted;
	}
	void add_edge(int u,int v,ll c,int id){
		e[ecnt].next = first[u];
		e[ecnt].u = u;
		e[ecnt].v = v;
		e[ecnt].id = id;
		e[ecnt].cp = c;
		first[u] = ecnt++;

		e[ecnt].next = first[v];
		e[ecnt].u = v;
		e[ecnt].v = u;
		e[ecnt].id = id;
		e[ecnt].cp = 0;
		first[v] = ecnt++;
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
		return lev[ed] != -1;
	}
	ll dfs(int p,ll minf){
		if(p == ed) return minf;
		for(int i = first[p]; ~i; i = e[i].next){
			int v = e[i].v;
			if(lev[v] > lev[p] && e[i].cp > 0){
				ll d = dfs(v,min(e[i].cp,minf));
				if(d > 0){
					e[i].cp -= d;
					e[i ^ 1].cp += d;
					return d;
				}
			}
		}
		return 0;
	}
	ll dinic(){
		ll max_flow = 0,cur;
		while(bfs()){
			while((cur = dfs(st,1LL << 60)) > 0)
				max_flow += cur;
		}
		return max_flow;
	}
	void Flood_fill(int p){
		S[p] = 1;
		for(int i = first[p]; ~i; i = e[i].next){
			int v = e[i].v;
			if(S[v] || e[i].cp <= 0) continue;
			Flood_fill(v);
		}
	}
	void A_Flood_fill(int p){
		S[p] = -1;
		for(int i = first[p]; ~i; i = e[i].next){
			int v = e[i].v;
			if(S[v] || e[i ^ 1].cp <= 0) continue;
			A_Flood_fill(v);
		}
	}
}MF;

int main(){
	freopen("milk6.in","r",stdin);
	freopen("milk6.out","w",stdout);
	int a,b;
	ll c;
	scanf("%d%d",&N,&M);
	MF.init(1,N);
	REP(i,M){
		scanf("%d%d%lld",&a,&b,&c);
		c = c * (M + 1) + 1;
		MF.add_edge(a,b,c,i);
		//MF.add_edge(b,a,c,i);
	}
	ll tmax_flow = MF.dinic();
	MF.Flood_fill(MF.st);
	MF.A_Flood_fill(MF.ed);
	ll anscnt = tmax_flow % (M + 1);
	printf("%lld %lld\n",tmax_flow / (M + 1),anscnt);
	if(tmax_flow){
		int tcnt = 0;
		for(int i = 0; tcnt < anscnt && i < MF.ecnt; i += 2){
			int tmp = S[MF.e[i].u] + S[MF.e[i].v];
			if(MF.e[i].cp == 0 && tmp != 2 && tmp != -2){
				printf("%d\n",MF.e[i].id);
				++tcnt;
			}
		}
	}
	return 0;
}


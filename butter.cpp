/*
ID:naturec1
PROG: butter
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

int N,P,C;
int pa[510];
int first[810],ecnt;
int dis[810],inq[810];

struct edge{
	int v,next,c;
}e[10000];

void Init(){
	MEM(first,-1);
	ecnt = 0;
}

void Add_edge(int u,int v,int c){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	e[ecnt].c = c;
	first[u] = ecnt;
}

int Cal(int ori){
	fill(dis + 1,dis + P + 1,INF);
	MEM(inq,0);
	dis[ori] = 0;
	queue<int> Q; while(!Q.empty()) Q.pop();
	Q.push(ori);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; ~i; i = e[i].next){
			int v = e[i].v;
			if(dis[v] > dis[x] + e[i].c){
				dis[v] = dis[x] + e[i].c;
				if(inq[v] == 0){
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	int res = 0;
	REP(i,N){
		if(dis[pa[i]] >= INF) return -1;
		else res += dis[pa[i]];
	}
	return res;
}

int main(){
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	Init();
	int a,b,c;
	scanf("%d%d%d",&N,&P,&C);
	REP(i,N) scanf("%d",pa + i);
	REP(i,C){
		scanf("%d%d%d",&a,&b,&c);
		Add_edge(a,b,c);
		Add_edge(b,a,c);
	}
	int ans = INF;
	REP(i,P){
		int res = Cal(i);
		//printf("%d : %d\n",i,res);
		if(res != -1) ans = min(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}


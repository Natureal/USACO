/*
ID:naturec1
PROG: stall4
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
const int MAXN = 210;

int N,M;
struct edge{
	int v,next;
};

struct Max_match{
	int mat[MAXN],used[MAXN];
	int first[MAXN],ecnt;
	edge e[MAXN * MAXN];
	void init(){
		MEM(first,-1);
		ecnt = 0;
	}
	void add_edge(int u,int v){
		e[ecnt].next = first[u];
		e[ecnt].v = v;
		first[u] = ecnt++;
	}
	bool find(int p){
		for(int i = first[p]; ~i; i = e[i].next){
			int v = e[i].v;
			if(used[v] == 0){
				used[v] = 1;
				if(mat[v] == 0 || find(mat[v])){
					mat[v] = p;
					return true;
				}
			}
		}
		return false;
	}
	int hungary(){
		int res = 0;
		MEM(mat,0);
		REP(i,N){
			MEM(used,0);
			if(find(i)) res++;
		}
		return res;
	}
}MM;

int main(){
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	int a,b;
	scanf("%d%d",&N,&M);
	MM.init();
	REP(i,N){
		scanf("%d",&a);
		REP(j,a){
			scanf("%d",&b);
			MM.add_edge(i,b);
		}
	}
	printf("%d\n",MM.hungary());
	return 0;
}

/*
ID:naturec1
PROG: job
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
const int MAXN = 40;

struct node{
	int pro,t;
	node(int tpro = 0,int tt = 0) : pro(tpro),t(tt) {}
	friend bool operator < (node a,node b){
		if(a.pro == b.pro) return a.t > b.t;
		return a.pro > b.pro;
	}
};

int N,M1,M2;
int t1[MAXN],t2[MAXN];
priority_queue<node> Q,Q2;
vector<int> g;

int main(){
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	scanf("%d%d%d",&N,&M1,&M2);
	REP(i,M1) scanf("%d",t1 + i),Q.push(node(t1[i],t1[i]));
	REP(i,M2) scanf("%d",t2 + i),Q2.push(node(t2[i],t2[i]));
	int ans1 = 0,ans2 = 0;
	REP(i,N){
		node cur = Q.top(); Q.pop();
		g.push_back(cur.pro);
		ans1 = max(ans1,cur.pro);
		cur.pro += cur.t;
		Q.push(cur);
	}
	sort(g.begin(),g.end(),greater<int>());
	for(int i = 0; i < g.size(); ++i){
		node cur = Q2.top(); Q2.pop();
		ans2 = max(ans2,g[i] + cur.pro);
		cur.pro += cur.t;
		Q2.push(cur);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}


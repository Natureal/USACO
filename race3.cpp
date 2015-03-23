/*
ID:naturec1
PROG: race3
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

int g[MAXN][MAXN];
int vis[MAXN],st,ed;
vector<int> ans1,ans2;

bool Check1(int p){
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	Q.push(st);
	MEM(vis,0);
	vis[st] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i = st + 1; i <= ed; ++i) if(g[x][i]){
			if(i == p) continue;
			if(!vis[i]){
				vis[i] = 1;
				Q.push(i);
			}
		}
	}
	return vis[ed] == 0;
}

int fa[MAXN];

bool Check2(int p){
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	MEM(vis,0);
	vis[p] = 1;
	for(int i = st; i <= ed; ++i) if(!vis[i] && g[p][i]){
		vis[i] = 1;
		Q.push(i);
	}
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i = st; i <= ed; ++i) if(g[x][i] || g[i][x]){
			if(i == p) continue;
			if(!vis[i]){
				vis[i] = 1;
				Q.push(i);
			}
		}
	}
	for(int i = st; i <= ed; ++i) if(vis[i] == 0) return true;
	return false;
}

int main(){
	freopen("race3.in","r",stdin);
	freopen("race3.out","w",stdout);
	int tot = 0;
	int a,b;
	while(scanf("%d",&a) != EOF){
		if(a == -1) break;
		if(a == -2){
			tot++;
			continue;
		}
		g[tot][a] = 1;
		while(cin >> a && a != -2) g[tot][a] = 1;
		tot++;
	}
	st = 0;
	ed = tot - 1;
	REP(i,ed - 1){
		if(Check1(i)){
			ans1.push_back(i);
			if(Check2(i)) ans2.push_back(i);
		}
	}
	printf("%d",(int)ans1.size());
	for(int i = 0; i < ans1.size(); ++i) printf(" %d",ans1[i]);
	puts("");
	printf("%d",(int)ans2.size());
	for(int i = 0; i < ans2.size(); ++i) printf(" %d",ans2[i]);
	puts("");
	return 0;
}


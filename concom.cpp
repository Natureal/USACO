/*
ID:naturec1
PROG: concom
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
#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int n;
vector<pii> g[105];
vector<int> ans;
int vis[105];
int own[105];

void Dfs(int p){
	for(int i = 0; i < g[p].size(); ++i){
		pii &t = g[p][i];
		if(vis[t.X]) continue;
		if(t.Y > 50){
			ans.push_back(t.X);
			vis[t.X] = 1;
			Dfs(t.X);
		}
		else{
			own[t.X] += t.Y;
		}
	}
	REP(i,100) if(own[i] > 50 && !vis[i]){
		ans.push_back(i);
		vis[i] = 1;
		Dfs(i);
	}
}

int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	int a,b,c;
	scanf("%d",&n);
	REP(i,n){
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back(MP(b,c));
	}
	REP(i,100){
		MEM(own,0);
		MEM(vis,0);
		vis[i] = 1;
		ans.clear();
		Dfs(i);
		sort(ans.begin(),ans.end());
		for(int j = 0; j < ans.size(); ++j) printf("%d %d\n",i,ans[j]);
	}
	return 0;
}


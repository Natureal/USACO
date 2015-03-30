/*
ID:naturec1
PROG: frameup
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

char g[50][50];
int W,H,tot;
int id[30];
int Up[30],Down[30],Left[30],Right[30];
int mx[30][30];
int deg[30],st_deg[30];
vector<vector<int> > ans;
vector<int> now_ans;

void Add_edge(int p){
	int cur;
	for(int j = Left[p]; j <= Right[p]; ++j){
		cur = g[Up[p]][j] - 'A';
		if(cur != p) mx[cur][p] = 1;
		cur = g[Down[p]][j] - 'A';
		if(cur != p) mx[cur][p] = 1;
	}
	for(int i = Up[p]; i <= Down[p]; ++i){
		cur = g[i][Left[p]] - 'A';
		if(cur != p) mx[cur][p] = 1;
		cur = g[i][Right[p]] - 'A';
		if(cur != p) mx[cur][p] = 1;
	}
}

void Dfs(int p,int num){
	if(num >= tot){
		vector<int> tmp;
		for(int i = now_ans.size() - 1; i >= 0; --i)
			tmp.push_back(now_ans[i]);
		ans.push_back(tmp);
		return;
	}
	REP(i,26) if(id[i]){
		if(deg[i] == 0){
			now_ans.push_back(i);
			deg[i] = -1;
			REP(j,26) if(mx[i][j]) deg[j]--;
			//	
			Dfs(i,num + 1);
			//
			now_ans.pop_back();
			deg[i] = 0;
			REP(j,26) if(mx[i][j]) deg[j]++;
		}
	}
}

int main(){
	freopen("frameup.in","r",stdin);
	freopen("frameup.out","w",stdout);
	MEM(mx,0);
	MEM(id,0);
	scanf("%d%d",&H,&W);
	REP(i,H) scanf("%s",g[i]);
	REP(i,H) REP(j,W) if(g[i][j] != '.'){
		int cur = g[i][j] - 'A';
		if(id[cur] == 0){
			id[cur] = 1;
			++tot;
			Up[cur] = Down[cur] = i;
			Left[cur] = Right[cur] = j;
		}
		else{
			Up[cur] = min(Up[cur],i);
			Down[cur] = max(Down[cur],i);
			Left[cur] = min(Left[cur],j);
			Right[cur] = max(Right[cur],j);
		}
	}
	REP(i,26) if(id[i]) Add_edge(i);	
	REP(i,26) REP(j,26) if(mx[i][j]) st_deg[j]++;
	REP(i,26) if(id[i] && st_deg[i] == 0){
		memcpy(deg,st_deg,sizeof(st_deg));
		now_ans.clear();
		now_ans.push_back(i);
		deg[i] = -1;
		REP(j,26) if(mx[i][j]) deg[j]--;
		Dfs(i,1);
	}
	sort(ans.begin(),ans.end());
	REP(i,ans.size()){
		REP(j,tot) printf("%c",ans[i][j] + 'A');
		puts("");
	}
	return 0;
}


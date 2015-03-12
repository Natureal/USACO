/*
ID:naturec1
PROG: fence
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

int F;
int deg[510];
int g[510][510];
vector<int> ans;
stack<int> st;

int Dfs(int p){
	st.push(p);
	REP(i,500) if(g[p][i]){
		g[p][i]--;
		g[i][p]--;
		Dfs(i);
		break;
	}
	return 0;
}

void Fleury(int ori){
	int brige;
	while(!st.empty()) st.pop();
	st.push(ori);
	while(!st.empty()){
		brige = 1;
		int x = st.top(); st.pop();
		REP(i,500) if(g[x][i]){
			brige = 0;
			break;
		}
		if(brige)	ans.push_back(x);
		else	Dfs(x);
	}
	for(int i = ans.size() - 1; i >= 0; --i)
		printf("%d\n",ans[i]);
}

int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int a,b;
	scanf("%d",&F);
	REP(i,F){
		scanf("%d%d",&a,&b);
		deg[a]++;
		deg[b]++;
		g[a][b]++;
		g[b][a]++;
	}
	bool flag = false;
	REP(i,500) if(deg[i] && deg[i] % 2){
		Fleury(i);
		flag = true;
		break;
	}
	if(flag == false){
		REP(i,500) if(deg[i]){
			Fleury(i);
			break;
		}
	}
	return 0;
}


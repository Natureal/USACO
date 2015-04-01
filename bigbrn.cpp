/*
ID:naturec1
PROG: bigbrn
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

int N,T;
bool g[1010][1010];
int dp[1010][1010];

int main(){
	freopen("bigbrn.in","r",stdin);
	freopen("bigbrn.out","w",stdout);
	int a,b;
	scanf("%d%d",&N,&T);
	REP(i,T){
		scanf("%d%d",&a,&b);
		g[a][b] = 1;
	}
	dp[N][N] = !g[a][b];
	int ans = 0;
	for(int i = N; i >= 1; --i){
		for(int j = N; j >= 1; --j) if(!g[i][j]){
			dp[i][j] = min(dp[i + 1][j + 1],min(dp[i + 1][j],dp[i][j + 1])) + 1;
			ans = max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}

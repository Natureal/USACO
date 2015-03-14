/*
ID:naturec1
PROG: rockers
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

int N,T,M;
int dp[30][30][30];
int v[30];

int main(){
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	scanf("%d%d%d",&N,&T,&M);
	REP(i,N) scanf("%d",v + i);
	REP(i,M) REP(j,N){
		for(int s = 0; s <= T; ++s){
			int &cur = dp[i][j][s];
			cur = dp[i][j - 1][s]; //no j
			if(s + v[j] <= T) cur = max(cur,dp[i][j - 1][s + v[j]] + 1);
			if(i > 1)
				for(int k = v[j]; k <= T; ++k)
					cur = max(cur,dp[i - 1][j - 1][k] + 1);
		}
	}
	int ans = 0;
	for(int s = 0; s <= T; ++s)
		ans = max(ans,dp[M][N][s]);
	printf("%d\n",ans);
	return 0;
}
		


/*
ID:naturec1
PROG: game1
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

int N;
int dp[110][110];
int v[110];

int main(){
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	int sum = 0;
	scanf("%d",&N);
	REP(i,N) scanf("%d",v + i),sum += v[i];
	for(int l = 1; l <= N; ++l){
		for(int i = 1; i <= N - l + 1; ++i){
			int j = i + l - 1;
			dp[i][j] = v[i] + min(dp[i + 2][j],dp[i + 1][j - 1]);
			dp[i][j] = max(dp[i][j],v[j] + min(dp[i + 1][j - 1],dp[i][j - 2]));
			//printf("dp[%d][%d] : %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d %d\n",dp[1][N],sum - dp[1][N]);
	return 0;
}


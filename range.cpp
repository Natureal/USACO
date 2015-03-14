/*
ID:naturec1
PROG: range
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
bool g[260][260];
char S[260][260];
int dp[260][260];
int cnt[260];

int main(){
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	scanf("%d",&N);
	REP(i,N) scanf("%s",S[i] + 1);
	REP(i,N) REP(j,N){
		if(S[i][j] == '1') g[i][j] = 1;
		else g[i][j] = 0;
	}
	REP(i,N){
		REP(j,N) if(g[i][j]){
			dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j],dp[i][j - 1])) + 1;
			cnt[dp[i][j]]++;
		}
	}
	for(int i = N - 1; i >= 2; --i) cnt[i] += cnt[i + 1];
	FOR(i,2,N) if(cnt[i]){
		printf("%d %d\n",i,cnt[i]);
	}
	return 0;
}



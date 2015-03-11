/*
ID:naturec1
PROG: nocows
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
const int mod = 9901;

int N,K;
int dp[205][105];

int main(){
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	scanf("%d%d",&N,&K);
	REP(i,K) dp[1][i] = 1;
	FOR(i,3,N){
		REP(j,K){
			for(int k = 1; k < i - 1; k += 2)
				dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % mod) % mod;
		}
	}
	printf("%d\n",(dp[N][K] - dp[N][K - 1] + mod) % mod);
	return 0;
}


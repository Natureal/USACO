/*
ID:naturec1
PROG: inflate
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

int M,N;
int dp[10010];
int v[10010],t[10010];

int main(){
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	scanf("%d%d",&M,&N);
	REP(i,N) scanf("%d%d",v + i,t + i);
	REP(i,N){
		for(int j = t[i]; j <= M; ++j)
			dp[j] = max(dp[j],dp[j - t[i]] + v[i]);
	}
	printf("%d\n",dp[M]);
	return 0;
}


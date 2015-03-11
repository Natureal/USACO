/*
ID:naturec1
PROG: stamps
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

int K,N;
int v[60];
int dp[3000010];

int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	MEM(dp,0x3f);
	dp[0] = 0;
	scanf("%d%d",&K,&N);
	REP(i,N) scanf("%d",v + i);
	REP(i,N){
		for(int j = v[i]; j <= 3000000; ++j) if(dp[j - v[i]] < INF){
			dp[j] = min(dp[j],dp[j - v[i]] + 1);
		}
	}
	for(int i = 1; i <= 3000000; ++i) if(dp[i] > K){
		printf("%d\n",i - 1);
		break;
	}
	return 0;
}


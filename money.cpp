/*
ID:naturec1
PROG: money
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

int V,N;
ll dp[100010];
int v[30];

int main(){
	//freopen("money.in","r",stdin);
	//freopen("money.out","w",stdout);
	
	while(scanf("%d%d",&V,&N) != EOF){
		MEM(dp,0);
		REP(i,V) scanf("%d",&v[i]);
		dp[0] = 1;
		REP(i,V){
			for(int j = v[i]; j <= N; ++j)
				dp[j] += dp[j - v[i]];
		}
		printf("%lld\n",dp[N]);
	}
	return 0;
}


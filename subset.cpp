/*
ID:naturec1
PROG: subset
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
ll dp[2000];

int main(){
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%d",&N);
	int sum = N * (N + 1) / 2;
	if(sum & 1){
		printf("0\n");
		return 0;
	}
	int top = sum / 2;
	dp[0] = 1;
	REP(i,N){
		for(int j = top; j >= i; --j){
			dp[j] += dp[j - i];
		}
	}
	printf("%lld\n",dp[top] / 2);
	return 0;
}


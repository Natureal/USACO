
/*
ID:naturec1
PROG: milk
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

int n,m;
pii p[5010];

int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d",&p[i].first,&p[i].second);
	sort(p + 1,p + m + 1);
	ll ans = 0;
	REP(i,m){
		int t = min(n,p[i].second);
		n -= t;
		ans += t * p[i].first;
		if(!n) break;
	}
	printf("%lld\n",ans);
	return 0;
}


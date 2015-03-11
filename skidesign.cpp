/*
ID:naturec1
PROG: skidesign
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

int N,tmax;
int h[1010];

int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	scanf("%d",&N);
	REP(i,N){
		scanf("%d",h + i);
		tmax = max(tmax,h[i]);
	}
	int ans = INF;
	for(int cur = 0; cur <= tmax; ++cur){
		int sum = 0;
		REP(i,N){
			if(h[i] > cur) sum += (h[i] - cur) * (h[i] - cur);
			else if(cur - h[i] > 17)
				sum += (cur - 17 - h[i]) * (cur - 17 - h[i]);
		}
		ans = min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}

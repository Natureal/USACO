/*
ID:naturec1
PROG: milk2
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

int n,l,r;
int cnt[1000010];

int main(){
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	scanf("%d",&n);
	int tmin = INF,tmax = 0;
	REP(i,n){
		scanf("%d %d",&l,&r);
		cnt[l]++;
		cnt[r]--;
		tmin = min(tmin,l);
		tmax = max(tmax,r);
	}
	int len1 = 0,len2 = 0,cur = 0,ans1 = 0,ans2 = 0;
	for(int i = tmin; i < tmax; ++i){
		cur += cnt[i];
		if(cur) len1++,len2 = 0;
		else len2++,len1 = 0;
		ans1 = max(ans1,len1);
		ans2 = max(ans2,len2);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}



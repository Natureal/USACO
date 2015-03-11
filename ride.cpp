/*
ID:naturec1
PROG: ride
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

char s1[10],s2[10];

int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	scanf("%s%s",s1 + 1,s2 + 1);
	int l1 = strlen(s1 + 1),l2 = strlen(s2 + 1);
	int ans1 = 1,ans2 = 1;
	REP(i,l1) ans1 = ans1 * (s1[i] - 'A' + 1) % 47;
	REP(i,l2) ans2 = ans2 * (s2[i] - 'A' + 1) % 47;
	if(ans1 == ans2) printf("GO\n");
	else printf("STAY\n");
	return 0;
}

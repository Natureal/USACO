/*
ID:naturec1
PROG: numtri
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

int R;
int g[1010][1010];

int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	scanf("%d",&R);
	REP(i,R){
		for(int j = 1; j <= i; ++j){
			scanf("%d",&g[i][j]);
		}
	}
	for(int i = R - 1; i >= 1; --i){
		for(int j = 1; j <= i; ++j){
			g[i][j] += max(g[i + 1][j],g[i + 1][j + 1]);
		}
	}
	printf("%d\n",g[1][1]);
	return 0;
}
	

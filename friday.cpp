/*
ID:naturec1
PROG: friday
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

int n;
int moth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int cnt[7];

bool Leap(int y){
	return ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0));
}

int main(){
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 12; ++j){
			cnt[(sum + 13) % 7]++;
			if(j == 2) sum += moth[j] + Leap(1900 + i - 1);
			else sum += moth[j];
		}
	}
	printf("%d %d",cnt[6],cnt[0]);
	REP(i,5) printf(" %d",cnt[i]);
	puts("");
	return 0;
}



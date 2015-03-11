/*
ID:naturec1
PROG: fact4
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

int main(){
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	ll sum = 1;
	scanf("%d",&N);
	FOR(i,2,N){
		sum *= (ll)i;
		while(sum % 10 == 0) sum /= 10;
		sum %= 1000;
	}
	printf("%d\n",(int)sum % 10);
	return 0;
}


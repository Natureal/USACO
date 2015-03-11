/*
ID:naturec1
PROG: kimbits
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

int N,L;
ll I;
int c[35][35];
int ans[35];

void Pre(){
	for(int i = 0; i <= 31; ++i)
		for(int j = 0; j <= i; ++j)
			c[i][j] = (i == 0 || j == 0) ? 1 : c[i - 1][j] + c[i - 1][j - 1];
}

int main(){
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	Pre();
	scanf("%d%d%lld",&N,&L,&I);
	I--;
	int one = L;
	REP(i,N){
		//puts zero
		int sum = 0;
		for(int j = min(N - i,one); j >= 0; --j)
			sum += c[N - i][j];
		if(I >= sum){
			ans[i] = 1;
			I -= sum;
			one--;
		}
		else ans[i] = 0;
	}
	REP(i,N) printf("%d",ans[i]);
	puts("");
	return 0;
}



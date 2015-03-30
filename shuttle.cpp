/*
ID:naturec1
PROG: shuttle
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
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int N;
vector<int> ans1,ans2;

int main(){
//	freopen("shuttle.in","r",stdin);
//	freopen("shuttle.out","w",stdout);
	scanf("%d",&N);
	if(N == 1){
		printf("1 3 2\n");
		return 0;
	}
	ans1.PB(2); ans1.PB(1);
	int f = -1;
	for(int i = 1; i <= N - 2; ++i){
		for(int j = 1; j <= i + 1; ++j) ans1.PB(2 * f);
		ans1.PB(f);
		f *= -1;
	}
	for(int i = 1; i <= N; ++i) ans1.PB(2 * f);
	f = -1;
	ans2.PB(-1); ans2.PB(2); ans2.PB(1);
	for(int i = 1; i <= N - 2; ++i){
		for(int j = 1; j <= i + 1; ++j) ans2.PB(2 * f);
		ans2.PB(f);
		f *= -1;
	}
	int st = N;
	int tot = 1;
	printf("%d",st);
	for(int i = 0; i < ans1.size(); ++i){
		st += ans1[i];
		if(tot % 20) printf(" ");
		printf("%d",st);
		if((++tot) % 20 == 0) puts("");
	}
	for(int i = ans2.size() - 1; i >= 0; --i){
		st += ans2[i];
		if(tot % 20) printf(" ");
		printf("%d",st);
		if((++tot) % 20 == 0) puts("");
	}
	if(tot % 20) puts("");
	return 0;
}
